class record
{

    friend class command;

private:
    char *name;
    int phone;
    int group;
public:
    record (const char *initial_name = 0, int initial_phone = 0, int initial_group = 0);
    record (const  record& i);
    ~record ();
    record& operator = (const record& rhs);

    int get_phone () const
    {
        return phone;
    }

    int get_group () const
    {
        return group;
    }

    const char *get_name() const
    {
        return (const char *)name;
    }

    int operator< (const record& b) const;
    int operator== (const record& b) const;
    int init (const char *initial_name = 0, int initial_phone = 0, int initial_group = 0);
};
