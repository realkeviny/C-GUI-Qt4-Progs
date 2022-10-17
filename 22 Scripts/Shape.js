function Shape(x,y)
{
    this.x = x;
    this.y = y;
}

Shape.prototype.area = function(){return 0;};

function Circle(x,y,radius){
    Shape.call(this,x,y);
    this.radius = radius;
}

Circle.prototype = new Shape;
Circle.prototype.area = function(){
    return Math.PI * this.radius * this.radius;
};

var circle = new Circle(0,0,50);
console.log(circle instanceof Circle);
console.log(circle instanceof Shape);
console.log(circle instanceof Object);
console.log(circle instanceof Array);