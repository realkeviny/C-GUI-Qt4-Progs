function square(x)
{
    return x*x;
}

function sum(array,unaryFunc)
{
    var result = 0;
    for(var i = 0;i < array.length;++i)
    {
        result += unaryFunc(array[i]);
    }
    return result;
}

var array = new Array(100);
for(var i =0;i < array.length; ++i)
{
    array[i] = (i * 257) % 101;
}

console.log(sum(array,square));
console.log(sum(array,function(x){return x*x;}));
console.log(sum([4,8,11,15],function(x){return x*x;}));