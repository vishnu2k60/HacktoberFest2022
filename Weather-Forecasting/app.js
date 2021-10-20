// selectors
const locationInput = document.querySelector(".input-location")
const submitButton = document.querySelector("#input-submit")
const weatherContainer = document.querySelector(".weather-info")
const weatherDetailsContainer = document.querySelector(".weather-details")
const suggestionList = document.querySelector(".suggestion")
const inputField = document.querySelector('.input')
const date = new Date()

// Templates
// Weather info

const weatherInfo = (location) => {
    return (
        `<div class="row px-3 mt-5 mb-3">
    <h1 class="large-font mr-3">
      ${(location.main.temp - 273.15).toFixed(0)} &#176;
    </h1>
    <div class="d-flex flex-column mr-3">
      <h2 class="mt-3 mb-0">${location.name}</h2>
      <small>${date.toDateString()}</small>
    </div>
    <div class="d-flex flex-column text-center">
      <img
        src="./assets/images/${location.weather[0].main}.svg"
        alt=""
        srcset=""
        width="55px"
      />
      <small>${location.weather[0].main}</small>
    </div>
  </div>`
    )
}

// Weather-details
const weatherDetails = (location) => {
    return (
        `<div class="row px-3">
                  <p class="light-text">Max Temp</p>
                  <p class="ml-auto">${(location.main.temp_max - 273.15).toFixed(0)} &#176</p>
                </div>
                <div class="row px-3">
                  <p class="light-text">Min Temp</p>
                  <p class="ml-auto">${(location.main.temp_min - 273.15).toFixed(0)} &#176</p>
                </div>
                <div class="row px-3">
                  <p class="light-text">Pressure</p>
                  <p class="ml-auto">${location.main.pressure} hpa</p>
                </div>
                <div class="row px-3">
                  <p class="light-text">Humidity</p>
                  <p class="ml-auto">${location.main.humidity} %</p>
                </div>
                <div class="row px-3">
                  <p class="light-text">Wind Speed</p>
                  <p class="ml-auto">${location.wind.speed} m/s</p>
                </div>`
    )
}

//Functions
const fetchWeather = async (c) => {
    weatherContainer.innerHTML = " "
    weatherDetailsContainer.innerHTML = " "


    const weather = await fetch(`https://api.openweathermap.org/data/2.5/weather?q=${c}&appid=ab87c853e98b4a1aa5aaa47a72e4e7d4`)
    const data = await weather.json()
    console.log(data);
    if (data.cod === '404') {
        let node = document.createElement('div')
        node.innerHTML = `<img
                  src="/assets/images/error.svg"
                  alt=""
                  width="80px"
                  srcset=""
                />
                <p>${data.message}</p>`
        weatherContainer.appendChild(node)
    } else {
        // Creating Weather-info 
        let node = document.createElement('div')
        node.innerHTML = weatherInfo(data)
        weatherContainer.appendChild(node)

        // Creating Weather-details
        let element = document.createElement('div')
        element.innerHTML = weatherDetails(data)
        weatherDetailsContainer.appendChild(element)
    }

    // Clearing input
    inputField.reset()

}

// Eventlisteners
submitButton.addEventListener('click', () => fetchWeather(locationInput.value))
suggestionList.addEventListener('click', (e) => fetchWeather(e.target.innerHTML))
