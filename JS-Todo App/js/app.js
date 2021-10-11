const form =document.querySelector('form');
const ul =document.querySelector('ul');
const button =document.querySelector('.refresh');
const input =document.querySelector('.userip');
const plus=document.querySelector('.plussymbol');


/*<li class="cardelements">
<span>Record A Video About DOM</span>
<a href="" class="dustbin">
<i class="far fa-trash-alt"></i>
</a>
</li> */
//const itemsArray=[];
let itemsArray = localStorage.getItem('items') ? JSON.parse(localStorage.getItem('items')) : [];
localStorage.setItem('items',JSON.stringify(itemsArray));
const data=JSON.parse(localStorage.getItem('items'));

const makelist =text=>{
    
const li=document.createElement('li');
li.className='cardelements';
li.textContent=text;

   
const link=document.createElement('a');
link.style.color="red";
link.href=" ";
link.className='dustbin';
link.innerHTML='<i class="far fa-trash-alt"></i>';
    
console.log(ul.classList);

li.appendChild(link);
ul.appendChild(li);
    
}
 
form.addEventListener('submit',adddata);
plus.addEventListener('click',adddata);
function adddata(e){
    e.preventDefault();
   itemsArray.push(input.value);
   localStorage.setItem('items',JSON.stringify(itemsArray));
   makelist(input.value);
   input.value=" ";
}

button.addEventListener('click',function(e){
   
    itemsArray=[];
    localStorage.clear();
   
});
data.forEach(item=>{
    makelist(item);
    ul.addEventListener('click',removefn);
    
});

function removefn(e){
    e.preventDefault();
    if(e.target.className==='far fa-trash-alt'){
        if(confirm('Are You Sure You Want To Delete This Item?')){
            e.target.parentElement.parentElement.remove();
            removeFromStorage(e.target.parentElement.parentElement);
        }
    }
}
function removeFromStorage(liitem){
    console.log('entered removefromstorage fn');
    itemsArray.forEach(function(singleElement,index){
       console.log(singleElement,index); 
        if(liitem.textContent===singleElement){
            itemsArray.splice(index,1);
            console.log(itemsArray);
        }
    });
    localStorage.setItem('items',JSON.stringify(itemsArray));
}