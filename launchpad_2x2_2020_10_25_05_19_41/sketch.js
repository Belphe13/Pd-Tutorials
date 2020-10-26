let flag_1 = false;
let flag_2 = false;
let flag_3 = false;
let flag_4 = false;

function preload() {
  soundFormats('mp3');
  hh = loadSound('audio/hh.mp3');
  hho = loadSound('audio/hho.mp3');
  kick = loadSound('audio/kick.mp3');
  snare = loadSound('audio/snare.mp3');
}


function setup() {
  frameRate(5);
  background(0);
  createCanvas(420, 420);
  strokeWeight(20);
  rect(10, 10, 200, 200); // 1
  rect(210, 10, 200, 200); // 2
  rect(10, 210, 200, 200); // 3
  rect(210, 210, 200, 200); // 4
}

function draw() {
  if (flag_1) {
    hh.setVolume(0.1);
    hh.play();
  }

  if (flag_2) {
    hho.setVolume(0.1);
    hho.play();
  }

  if (flag_3) {
    kick.setVolume(0.1);
    kick.play();
  }

  if (flag_4) {
    snare.setVolume(0.1);
    snare.play();
  }
}

function touchStarted() {
  for (let i = 0; i < touches.length; i++) {
    if (touches[i].x <= 200 && touches[i].y <= 200) {
      if (!flag_1) {
        fill(255, 208, 75);
        flag_1 = true;
      } else {
        fill(255);
        flag_1 = false;
      }
      rect(10, 10, 200, 200); // 1
    }
    if (touches[i].x > 200 && touches[i].y <= 200) {
      if (!flag_2) {
        fill(31, 164, 99);
        flag_2 = true;
      } else {
        fill(255);
        flag_2 = false;
      }
      rect(210, 10, 200, 200); // 2
    }
    if (touches[i].x <= 200 && touches[i].y > 200) {
      if (!flag_3) {
        fill(70, 136, 244);
        flag_3 = true;
      } else {
        fill(255);
        flag_3 = false;
      }
      rect(10, 210, 200, 200); // 3
    }
    if (touches[i].x > 200 && touches[i].y > 200) {
      if (!flag_4) {
        fill(231, 69, 60);
        flag_4 = true;
      } else {
        fill(255);
        flag_4 = false;
      }
      rect(210, 210, 200, 200); // 4
    }
  }
}

function mouseReleased() {
 if (touches.length == 0) {
    if (mouseX <= 200 && mouseY <= 200) {
      if (!flag_1) {
        fill(255, 208, 75);
        flag_1 = true;
      } else {
        fill(255);
        flag_1 = false;
      }
      rect(10, 10, 200, 200); // 1
    }
    if (mouseX > 200 && mouseY <= 200) {
      if (!flag_2) {
        fill(31, 164, 99);
        flag_2 = true;
      } else {
        fill(255);
        flag_2 = false;
      }
      rect(210, 10, 200, 200); // 2
    }
    if (mouseX <= 200 && mouseY > 200) {
      if (!flag_3) {
        fill(70, 136, 244);
        flag_3 = true;
      } else {
        fill(255);
        flag_3 = false;
      }
      rect(10, 210, 200, 200); // 3
    }
    if (mouseX > 200 && mouseY > 200) {
      if (!flag_4) {
        fill(231, 69, 60);
        flag_4 = true;
      } else {
        fill(255);
        flag_4 = false;
      }
      rect(210, 210, 200, 200); // 4
    }
 }
}
