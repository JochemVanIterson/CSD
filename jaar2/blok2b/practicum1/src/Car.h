class SteeringWheel {
  public:
    SteeringWheel();
    int getAngle();
  private:
    int angle;
};

class Car {
  public:
    Car(std::string brnd, std::string clr);
    Car(std::string brnd, std::string clr, int spd, int drctn);
    SteeringWheel stWheel;
    void setSpeed(int input);
    void setDirection(int input);
    int getSpeed();
    int getDirection();
    std::string getColor();
    void printOptions();
  private:
    std::string brand = "";
    std::string color = "";
    int speed = 0;
    int direction = 0;
};
