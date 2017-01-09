//
// adapted from
// http://codepen.io/maxpowa/pen/VKXmrW
//
//


var stars = [],
    WIDTH = window.innerWidth,
    HEIGHT = window.innerHeight,
    FPS = 22, // Frames per second
    NUM_STARS = 555; // Number of stars
var originX = WIDTH / 2;
var originY = HEIGHT / 2;
var planets = [];

var hover = [0, 0, 0, 0, 0];

function setup() {
  var canvas = createCanvas(WIDTH, HEIGHT);
  canvas.parent('container');
  
  // Push stars to array
  for (var i = 0; i < NUM_STARS; i++) {
  	stars.push({
  	    x: 0,
  	    y: 0,
  	    offset: Math.random() * 360,
  	      // Weight orbit a little to be outside origin
  	    orbit: (Math.random()+0.01) * max(222),
  	    radius: Math.random() * 2,
  	    vx: Math.floor(Math.random() * 10) - 5,
  	    vy: Math.floor(Math.random() * 10) - 5,
  	    c: 0
  	});
  }

  for(var i = 0; i < 5; i++) {
  	if(i >= 1)
  		planets.push(new Planet(44 * i));
  	else
  		planets.push(new Planet(0));
  }
  

  $("#mercury").css({top: planets[1].y * 0.5, left: planets[1].x * 0.5});
  $("#venus").css({top: planets[2].y , left: planets[2].x });
  $("#earth").css({top: planets[3].y , left: planets[3].x });
  $("#mars").css({top: planets[4].y , left: planets[4].x });
  frameRate(FPS);
  loop();
}

function draw() {
  background(24, 24, 24);
  push();
  noFill();
  stroke(240,240,240, 1);
  colorMode(RGB, 255, 255, 255, 1);
  strokeCap(ROUND);
  strokeWeight(2);
  for (var i = 0, x = stars.length; i < x; i++) {
    var s = stars[i];
 	ellipse(s.x, s.y, s.radius, 0);
  }
  pop();
  update();
}

function update() {
  for (var i = 0, x = stars.length; i < x; i++) {
    var s = stars[i];
    var rad = (frameCount * (1/(s.orbit * 2 + s.offset)) + s.offset) % TAU;
    s.x = (originX + cos(rad)*(s.orbit * 2));
    s.y = (originY + sin(rad)*(s.orbit));
  }
  for(var i = 0; i < 5; i++) {
  	planets[i].update();
  }

  
  $("#mercury").css({top: planets[1].y, left: planets[1].x});

  $("#venus").css({top: planets[2].y, left: planets[2].x});

  $("#earth").css({top: planets[3].y, left: planets[3].x});

  $("#mars").css({top: planets[4].y, left: planets[4].x});
}


function Planet(orbit) {
  this.x = 0;
	this.y = 0;
  this.offset = 1;
	this.orbit = orbit;
	this.radius = 15;
	this.vx =  Math.floor(Math.random() * 10) - 5;
	this.vy = Math.floor(Math.random() * 10) - 5;
  var over = 0;

	this.render = function() {
		push();
	    noFill();
	    stroke(240,240,240, 1);
	    colorMode(RGB, 255, 255, 255, 1);
	    strokeCap(ROUND);
	    strokeWeight(2);
	    ellipse(this.x, this.y, this.radius, this.radius);
	    pop();
	}

	this.update = function() {
	   	var rad = (frameCount * (1/(this.orbit * 2 + this.offset)) + this.offset) % TAU;
	    this.x = (originX + cos(rad)*(this.orbit * 2));
	    this.y = (originY + sin(rad)*(this.orbit));
      var distance = dist(mouseX, mouseY, this.x, this.y); 
	}
}


function windowResized() {
    WIDTH = window.innerWidth,
    HEIGHT = window.innerHeight,
  	originX = WIDTH / 2,
 	  originY = HEIGHT / 2,
    resizeCanvas(WIDTH, HEIGHT);
}


