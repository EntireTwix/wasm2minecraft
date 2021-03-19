struct Lock
{
private:
    uint16_t pin;
    bool state = false;

public:
    Lock() = delete;
    Lock(uint16_t pin) : pin(pin) {}

    bool Get() const
    {
        return state;
    }
    bool Set(uint16_t attempt, bool new_state)
    {
        if (pin != attempt)
        {
            return false;
        }

        state = new_state;
        return true;
    }
};
