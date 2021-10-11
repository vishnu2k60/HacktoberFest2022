console.log("project started");

function getHistory(){
    return document.getElementById("history-value").innerText;
}
function printHistory(num){
    document.getElementById("history-value").innerText=num;
}


function getOutput(){
    return document.getElementById("output-value").innerText;
}
function printOutput(num){
    if(num==""){
        document.getElementById("output-value").innerText=num;
    }
    else{
    document.getElementById("output-value").innerText=getFormattedNumber(num);
    }
}

function getFormattedNumber(num){
    if (num=="-"){
        return "";
    }
    var n=Number(num);
    var val=n.toLocaleString("en");
    return val;
}
function reverseNumberFormat(num){
    return Number(num.replace(/,/g,''));
}
var operator=document.getElementsByClassName("operator");
for(var i=0;i<operator.length;i++){
    operator[i].addEventListener('click',function(){
        if(this.id=='clear'){
            printHistory('');
            printOutput('');
        }
        else if(this.id=='backspace'){
            var op=reverseNumberFormat(getOutput()).toString();
            if(op){
                op=op.substr(0,op.length-1);
                printOutput(op);
            }
            
        }
        else{
            var op=getOutput();
            var history=getHistory();
            if(op=="" && history!=0){
                if(isNaN(history[history.length-1])){
                    history=history.substr(0,history.length-1);
                }
            }
            if(op!="" || history!=""){
                op= op=="" ? op:reverseNumberFormat(op);
                history=history+op;
                if(this.id=="="){
                    var result=eval(history);
                    printOutput(result);
                    printHistory("");
                }
                else{
                    history=history+this.id;
                    printHistory(history);
                    printOutput("");
                }
            }
        }

    });
}
var number=document.getElementsByClassName("number");
for(var i=0;i<number.length;i++){
    number[i].addEventListener('click',function(){
        var op=reverseNumberFormat(getOutput());
        if(op!=NaN){
            op=op+this.id;
            printOutput(op);
        }
    })
}