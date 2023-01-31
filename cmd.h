#include "record_list.h"

enum cmd_type
{ CMD_NONE, CMD_QUIT, CMD_SELECT, CMD_INSERT, CMD_DELETE };

enum op_type
{ OP_NONE, OP_AND, OP_OR };

enum cond_type
{COND_NONE, COND_EQ, COND_NE, COND_LT, COND_GT, COND_LE, COND_GE };

class command: public record
{
  private:
    cmd_type type;
    cond_type c_name;
    cond_type c_phone;
    cond_type c_group;
    op_type operation;
  public:
    command(): record()
    {
        type = CMD_NONE;
        c_name = COND_NONE;
        c_phone = COND_NONE;
        c_group = COND_NONE;
        operation = OP_NONE;
    }

    int init(const char* name, int ph, int gr)
    {
        return ((record*)this)->init(name, ph, gr);
    }

    void print_cmd();
    int init_str(const char* str);
    int apply(record_list** hash_func, int N);

    int if_there_operation();
    int if_there_name();
    int if_there_group();
    int if_there_phone();
    int if_cond_true_for_name(const char* list_name);
    int if_cond_true_for_phone(int list_phone);
    int if_cond_true_for_group(int list_group);
    void print_name();
    void print_phone();
    void print_group();
    int if_this_elem_is_good_without_hash(record_node* elem);
    int if_this_elem_is_good_with_hash(record_node* elem);
    void print_good_elements(record_node* elem);
    void select_without_hash(record_list** hash_func, int N);
    void select_with_hash(record_list** hash_func, int N);
    void delete_without_hash(record_list** hash_func, int N);
    void delete_with_hash(record_list** hash_func, int N);
};

int func_words(const char* str, const char* t, char**words);
