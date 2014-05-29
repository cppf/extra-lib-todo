void setup()
{
  size(800, 600, P3D);
  smooth();
  noStroke();
}

void draw()
{
  background(255);
  translate(400, 300, -800);
  lights();
  rotateX(mouseX/100.0);
  rotateY(mouseY/100.0);
  for(int i=0; i<80; i++)
  {
    float x = 200*randomGaussian();
    float y = 100*exp(-0.01*x); // + 10*randomGaussian();
    float z = 20*randomGaussian();
    float width = abs(0.07*(x+y) + 10*randomGaussian());
    float height = abs(0.1*(x+y) + 10*randomGaussian());
    int cRed = (int) abs(40*randomGaussian());
    int cGreen = 255 - (int) abs(40*randomGaussian());
    int cBlue = (int) abs(40*randomGaussian());
    fill(cRed, cGreen, cBlue);
    // rect(x, y, width, height);
    pushMatrix();
    translate(x, y, z);
    box(width);
    popMatrix();
  }
}

