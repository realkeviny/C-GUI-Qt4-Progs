const MAX = 1000;
var isPrime = new Array(MAX);

for(var i=2;i<MAX;++i)
{
    isPrime[i] = true;
}

for(var i=2;i<MAX;++i)
{
    if(isPrime[i])
    {
        for(var j = i;i*j < MAX;++j)
        {
            isPrime[i*j]=false;
        }
    }
}

for(var i =2;i < MAX;++i)
{
    if(isPrime[i])
        console.log(i)
}

var x;
typeof x;

x=null;
typeof x;

x=true;
typeof x;

x=5;
typeof x;

x="Hello";
typeof x;

console.log(x);