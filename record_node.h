#include "record.h"
#include "stdio.h"

class record_node: public record
{
    friend class record_list;
    private:
        record_node *next;

    public:
        record_node (const char *in = 0, int ip = 0, int ig = 0): record(in, ip, ig)
        {
            next = NULL;
        }

        record_node (const record_node& i): record(i)
        {
            next = i.next;
        }

        record_node& operator = (const record_node& i)
        {
            *((record*) this) = i;
            next = i.next;
            return *this;
        }

        int init (const char *in, int ip, int ig)
        {
            record::init(in, ip, ig);
            next = 0;
            return 0;
        }

        record_node* get_next() const
        {
            return next;
        }

        void set_next(record_node *p)
        {
            next = p;
        }

};
