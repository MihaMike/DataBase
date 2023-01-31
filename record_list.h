#include "record_node.h"
#include "stdio.h"

class record_list
{
    private:
        record_node *head;
        record_node *curr;
    public:
        record_list()
        {
            head = 0;
            curr = 0;
        }

        ~record_list()
        {
            record_node *tmp;
            while(head!=0)
            {
               tmp=head;
               head=head->get_next();
               delete tmp;
            }
        }

        void add(record new_record)
        {
            record_node *tmp = new record_node;
            tmp->init(new_record.get_name(), new_record.get_phone(), new_record.get_group());
            if (curr->next != NULL)
                tmp->next = curr->next;
            curr->next = tmp;
        }

        void del_next()
        {
            if(curr->next->next == NULL)
            {
                curr->next = NULL;
                delete curr->next;
                return;
            }

            record_node *tmp = (curr->next)->next;
            curr->next = NULL;
            delete curr->next;
            curr->next = tmp;
        }

        void add_next(record_node *p)
        {
            p->next = curr->next;
            curr->next = p;
            curr = p;
        }

        void goto_next()
        {
            curr = curr->next;
        }

        void goto_head()
        {
            curr = head;
        }

        void add_head(record_node* p)
        {
            p->next = head;
            head=p;
        }

        void del_head()
        {
            if(head==NULL) return;

            if(head->next == NULL)
            {
              head = NULL;
              delete head;
              return;
            }

            record_node *tmp = head->next;
            delete head;
            head = tmp;
            curr = head;
        }

        record_node* get_head()
        {
            return head;
        }

        record_node* get_curr()
        {
            return curr;
        }

        int isempty()
        {
            if (head == NULL)
                return 1;
            else
                return 0;
        }

        void set_head(record_node *p)
        {
            head = p;
        }

};
