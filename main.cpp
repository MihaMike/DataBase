#include <stdio.h>
#include <stdlib.h>
#include "cmd.h"
#include "read_print.h"

#define first_letter  'A'
#define second_letter 'z'

#define LEN 100


int main()
{

    int ret,k;

    const char* fin ="a.txt";
    char str[LEN];

    int N;

    N = (int(first_letter)-int(second_letter)+1);

    record_list** hash_func = new record_list*[N*N];

    for(k=0;k<N*N;k++)
    {
        hash_func[k] = new record_list;
    }

    ret = read_list(fin, hash_func, N);
    printf("ret is: %d", ret);

    if(ret>0)
    {
        printf("The original list: \n");
        print_list(hash_func,N);
    }

    command CMD;

    while(2>1)
    {
      printf("\n");

      printf("Input command: ");
      fgets(str,LEN,stdin);

      CMD.init_str(str);

      CMD.print_cmd();
      k = CMD.apply(hash_func, N);

      k = -2;

      if(k==-2) break;
      if(k==-1) continue;

      printf("\nThe new list: \n");
      print_list(hash_func, N);
    }

 //   for(k=0;k<122*123;k++)
  //  {
  //      delete hash_func[k];
  //  }

  //  delete hash_func;

    return 0;
}
