
class Button
{

public:
    Button(int pin);
    ~Button();

    void begin();
    bool isButtonPressed();

private:
    int _pin{0};
    bool value{false};
};
