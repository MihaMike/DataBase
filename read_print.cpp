#include <stdio.h>
#include "record_list.h"

#define LEN 123
#define NMAX 20

int hash_(const char* name, int N)
{
    int k1, k2;
    char s1, s2;

    s1 = name[0];
    s2 = name[1];

    k1 = int(s1);
    k2 = int(s2);


    return k1*N+k2;
}


int read_list(const char *fin, record_list **hash_func, int N)
{
    FILE* fp;
    int i = 0, phone, group;
    char *name = new char[LEN];
    int k;

    record_node *p=0;

    if (!(fp = fopen(fin, "r")))
        return -1;


    while (fscanf(fp, "%s %d %d", name, &phone, &group) == 3)
    {
        p=new record_node(name, phone, group);

        k = hash_(name, N);

        hash_func[k]->add_head(p);
        i++;
    }


    delete [] name;

    if (!feof(fp))
    {
        fclose(fp);
        return -2;
    }

    return i;
}

void print_list (record_list **hash_func, int N)
{
    int i;

    printf("FUCK ALL");

    for(i=0;i<N*N;i++)
    {
       if(hash_func[i]->isempty()) continue;
       hash_func[i]->goto_head();

       for (; hash_func[i]->get_curr();)
       {
          const char* name_name = hash_func[i]->get_curr()->get_name();
          int phone_phone = hash_func[i]->get_curr()->get_phone();
          int group_group = hash_func[i]->get_curr()->get_group();

          printf("%s %d %d\n", name_name, phone_phone, group_group);

          if(!hash_func[i]->get_curr()->get_next()) break;
          else hash_func[i]->goto_next();
       }
    }
}
