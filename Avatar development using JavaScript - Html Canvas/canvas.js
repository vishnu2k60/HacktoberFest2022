let c = document.getElementById("myCanvas");
let ctx = c.getContext("2d");

let drawLine = (startX, startY, endX, endY) => {
  ctx.beginPath();
  ctx.moveTo(startX, startY);
  ctx.lineTo(endX, endY);
  ctx.stroke();
};
let drawCircle = (
  centerX,
  centerY,
  radius,
  startingAngle,
  endingAngle,
  color
) => {
  ctx.beginPath();
  ctx.arc(centerX, centerY, radius, startingAngle, endingAngle);
  ctx.fillStyle = color;
  ctx.fill();
  ctx.stroke();
};
//head of stick man
drawCircle(250, 250, 150, 0, 2 * Math.PI, "transparent");
//Eyes
let drawEyes = (radius, color) => {
  //LeftEye
  drawCircle(300, 200, radius, 0, 2 * Math.PI, color);

  //Right Eye

  drawCircle(200, 200, radius, 0, 2 * Math.PI, color);
};

//Nose
let drawNose =(type) =>{
    if(type === "crooked"){
        drawLine(250,225,200,275);
        drawLine(200,275,250,275);
    }
    else{
        drawCircle(250,250,20,0, Math.PI,"transparent");
        drawLine(230,250,250,225);
        drawLine(270,250,250,225);
    }
};

//Mouth

let drawMouth =(expression) =>{
    if(expression === "surprised"){
        drawCircle(250,325,40,0,2*Math.PI,"transparent");
        
    }
    else if(expression === "happy"){
        drawCircle(250,300,40,0,Math.PI,"transparent");

    }
    else{
        
        drawLine(200,325,300,325);
        
    }
};
let getRndInteger = (min, max) => {
  return Math.floor(Math.random() * (max - min + 1) ) + min;
};

let drawRandomFace = () => {
  let eyeRadius = getRndInteger(1,30);
  let eyeColor = ["brown","blue","green"][getRndInteger(0,2)]
  drawEyes(eyeRadius, eyeColor);
  let noseType =["crooked","button"][getRndInteger(0,1)]
  drawNose(noseType);
  let mouthExpression =["surprised","happy","flat"][getRndInteger(0,2)]
  drawMouth(mouthExpression);

};

drawRandomFace()


