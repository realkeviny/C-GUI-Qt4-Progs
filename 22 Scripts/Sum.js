function square(x)
{
    return x*x;
}

function sum()
{
    var unaryFunc = function(x){return x;};
    var i = 0;
    if(typeof arguments[0] == "function")
    {
        unaryFunc = arguments[0];
        i=1;
    }
    var result = 0;
    while(i < arguments.length)
    {
        result  += unaryFunc(arguments[i++]);
    }
    return result;
}

console.log(sum(square,1,2,3,4,5,6));