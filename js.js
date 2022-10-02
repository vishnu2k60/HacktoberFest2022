var canvas = document.querySelector('canvas');

canvas.width=window.innerWidth;
canvas.height=window.innerHeight;

var c=canvas.getContext('2d');

// canvas

var mouse={
    x:undefined,
    y:undefined
}

var maxRadius=600;
var minRadius=259;

var colorArray=[
    'red',
    'blue',
    'green',
    'yellow',
    'white'
];

window.addEventListener("mousemove",function(event){
    mouse.x=event.x;
    mouse.y=event.y;
    console.log(mouse);
});


window.addEventListener("resize",function(){
    canvas.width=window.innerWidth;
    canvas.height=window.innerHeight;
    init();
});


function Circle(x,y,dx,dy,radius,color){
    this.color=color;
    this.x=x;
    this.y=y;

    this.dx=dx;
    this.dy=dy;

    this.radius=radius;
    this.minRadius=radius;

    this.draw=function(){
        c.beginPath();
        c.arc(this.x,this.y,this.radius,0,Math.PI*2,false,);
        c.strokeStyle=this.color;
        c.stroke();
        c.fillStyle=this.inColor;
        c.fill();
    }

    this.update=function(){
        if(this.x+this.radius > innerWidth || this.x-this.radius < 0) this.dx=-this.dx;
        if(this.y+this.radius > innerHeight || this.y-this.radius < 0) this.dy=-this.dy;
    
        this.x+=this.dx;
        this.y+=this.dy;       
        
        //inter-acitvity
        if(mouse.x - this.x < 50 && mouse.x - this.x > -50 
            &&  mouse.y - this.y < 50 && mouse.y - this.y > -50 ){

                if(this.radius<maxRadius){

                    this.radius +=2.5; 
                }
        }
        else if (this.radius > this.minRadius) {
            this.radius-=0.5;
        }

        this.draw();
    }
}


var circleArray=[];    

function init(){
    
    circleArray=[];
    for(var i=0;i<300;i++){
     var radius=Math.random()*10+2;
     var x=Math.random()*(innerWidth-radius*2)+radius;
     var y=Math.random()*(innerHeight-radius*2)+radius;
     var dx=(Math.random()-0.5)*2;
     var dy=(Math.random()-0.5)*2;
     var color='#'+(Math.random()*0xFFFFFF<<0).toString(16);

     circleArray.push(new Circle(x,y,dx,dy,radius,color));
    }
}

init();

function animate(){
    requestAnimationFrame(animate);
    c.clearRect(0,0,innerWidth,innerHeight);

    for(var i=0;i<circleArray.length;i++)
    {
        circleArray[i].update();
    }

}

animate();
