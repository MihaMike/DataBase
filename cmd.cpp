#define LEN 123
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "cmd.h"
#include "read_print.h"


void command::print_group()
{
     switch (c_group)
     {
           case (COND_EQ):
           {
                 printf("group = %d ",group);
                 break;
           }

           case (COND_NE):
           {
                printf("group <> %d ",group);
                break;
           }

           case (COND_LT):
           {
                printf("group < %d ",group);
                break;
           }

           case (COND_GT):
           {
                printf("group > %d ",group);
                break;
           }

           case (COND_LE):
           {
               printf("group <= %d ",group);
               break;
           }

           case (COND_GE):
           {
               printf("group >= %d ",group);
               break;
           }

           case (COND_NONE):
            {
                return;
            }
     }
}


void command::print_phone()
{
     switch (c_phone)
     {
           case (COND_EQ):
           {
                 printf("phone = %d ",phone);
                 break;
           }

           case (COND_NE):
           {
                printf("phone <> %d ",phone);
                break;
           }

           case (COND_LT):
           {
                printf("phone < %d ",phone);
                break;
           }

           case (COND_GT):
           {
                printf("phone > %d ",phone);
                break;
           }

           case (COND_LE):
           {
               printf("phone <= %d ",phone);
               break;
           }

           case (COND_GE):
           {
               printf("phone >= %d ",phone);
               break;
           }

           case (COND_NONE):
            {
                return;
            }
     }
}

void command::print_name()
{
     switch (c_name)
     {
           case (COND_EQ):
           {
                 printf("name = %s ",name);
                 break;
           }

           case (COND_NE):
           {
                printf("name <> %s ",name);
                break;
           }

           case (COND_LT):
           {
                printf("name < %s ",name);
                break;
           }

           case (COND_GT):
           {
                printf("name > %s ",name);
                break;
           }

           case (COND_LE):
           {
               printf("name <= %s ",name);
               break;
           }

           case (COND_GE):
           {
               printf("name >= %s ",name);
               break;
           }

           case (COND_NONE):
           {
               return;
           }
     }
}

void command::print_cmd()
{
   printf("Our command is: ");

   switch (type)
   {
       case (CMD_NONE):
       {
          return;
       }

       case(CMD_SELECT):
       {
           printf("select ");
           break;
       }

       case(CMD_DELETE):
       {
           printf("delete ");
           break;
       }

       case (CMD_QUIT):
       {
            printf("quit\n");
            return;
       }

       case (CMD_INSERT):
        {
            printf("insert %s %d %d\n", name, phone, group);
            return;
        }
   }


   if( !(if_there_name()) && !(if_there_phone()) && !(if_there_group()) ) return;

   printf("where ");

   if(operation==OP_NONE)
   {
       if(if_there_name())
       {
          print_name();
       }

       if(if_there_phone())
       {
          print_phone();
       }

       if(if_there_group())
       {
          print_group();
       }

       printf("\n");
       return;
   }


   const char* oper;

   if(operation==OP_AND) oper = "and ";
   else oper = "or ";

   if(if_there_name())
   {
     print_name();
     printf("%s",oper);

     if(if_there_phone())
     {
         print_phone();
     }
     else
     {
         print_group();
     }
   }
   else
   {
      print_phone();
      printf("%s",oper);
      print_group();
   }

   printf("\n");
}

int command::if_cond_true_for_phone(int list_phone)
{
     switch (c_phone)
     {
          case(COND_EQ):
          {
              if(list_phone==phone) return 1;
              else return 0;
          }

          case(COND_NE):
          {
              if(list_phone!=phone) return 1;
              else return 0;
          }

          case(COND_GT):
          {
             if(list_phone>phone) return 1;
             else return 0;
          }

          case(COND_LT):
          {
             if(list_phone<phone) return 1;
             else return 0;
          }

          case(COND_LE):
          {
             if(list_phone<=phone) return 1;
             else return 0;
          }

          case(COND_GE):
          {
             if(list_phone>=phone) return 1;
             else return 0;
          }

          case (COND_NONE):
          {
              return 1;
          }

     }

     return 1;
}


int command::if_cond_true_for_group(int list_group)
{
     switch (c_group)
     {
          case(COND_EQ):
          {
              if(list_group==group) return 1;
              else return 0;
          }

          case(COND_NE):
          {
              if(list_group!=group) return 1;
              else return 0;
          }

          case(COND_GT):
          {
             if(list_group>group) return 1;
             else return 0;
          }

          case(COND_LT):
          {
             if(list_group<group) return 1;
             else return 0;
          }

          case(COND_LE):
          {
             if(list_group<=group) return 1;
             else return 0;
          }

          case(COND_GE):
          {
             if(list_group>=group) return 1;
             else return 0;
          }

          case (COND_NONE):
          {
              return 1;
          }
     }

     return 1;

}


int command::if_cond_true_for_name(const char* list_name)
{
     switch (c_name)
     {
          case(COND_EQ):
          {
              if(strcmp(list_name,name)==0) return 1;
              else return 0;
          }

          case(COND_NE):
          {
              if(!strcmp(list_name,name)) return 1;
              else return 0;
          }

          case(COND_GT):
          {
             if(strcmp(list_name,name)>0) return 1;
             else return 0;
          }

          case(COND_LT):
          {
             if(strcmp(list_name,name)<0) return 1;
             else return 0;
          }

          case(COND_LE):
          {
             if(strcmp(list_name,name)<=0) return 1;
             else return 0;
          }

          case(COND_GE):
          {
             if(strcmp(list_name,name)>=0) return 1;
             else return 0;
          }

          case (COND_NONE):
          {
              return 1;
          }
     }

     return 1;

}

int command::if_there_operation()
{
    if (operation==OP_NONE)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int command::if_there_name()
{
    if (c_name==COND_NONE) return 0;
    else return 1;
}

int command::if_there_group()
{
    if (c_group==COND_NONE) return 0;
    else return 1;
}

int command::if_there_phone()
{
    if (c_phone==COND_NONE) return 0;
    else return 1;
}


int command::if_this_elem_is_good_without_hash(record_node* elem)
{
            if(if_there_operation())
            {
                  int cond1 = 0;
                  int cond2 = 0;

                  cond1 = if_cond_true_for_phone(elem->get_phone());
                  cond2 = if_cond_true_for_group(elem->get_group());

                  if(operation==OP_AND)
                  {
                     if(cond1&&cond2) return 1;
                     else return 0;
                  }
                  else
                  {
                     if(cond1||cond2) return 1;
                     else return 0;
                  }
            }
            else
            {
                  int cond1 = 0;

                  if(if_there_phone())
                  {
                      cond1 = if_cond_true_for_phone(elem->get_phone());
                  }
                  else
                  {
                      cond1 = if_cond_true_for_group(elem->get_group());
                  }

                  if(cond1) return 1;
                  else return 0;
            }

}

int command::if_this_elem_is_good_with_hash(record_node* elem)
{
   int cond;

   if(if_there_operation())
   {
      if(if_there_phone())
      {
          cond = if_cond_true_for_phone(elem->get_phone());
      }
      else
      {
          cond = if_cond_true_for_group(elem->get_group());
      }

      if(operation==OP_AND)
      {
          if(1 && cond) return 1;
          else return 0;
      }
      else
      {
          return 1;
      }
   }
   else
   {
       return 1;
   }
}

void command::print_good_elements(record_node* elem)
{
    const char* name_name = elem->get_name();
    int phone_phone = elem->get_phone();
    int group_group = elem->get_group();

    printf("%s %d %d\n", name_name, phone_phone, group_group);
}

void command::select_without_hash(record_list** hash_func, int N)
{

       int i;

       for(i=0;i<N;i++)
       {
          if(hash_func[i]->isempty()) continue;
          hash_func[i]->goto_head();

          for(;hash_func[i]->get_curr();)
          {

            if(if_this_elem_is_good_without_hash(hash_func[i]->get_curr()))
            {
               print_good_elements(hash_func[i]->get_curr());
            }

            if(hash_func[i]->get_curr()->get_next()) hash_func[i]->goto_next();
            else break;
         }
       }
}

void command::delete_without_hash(record_list** hash_func, int N)
{

       int i;

       for(i=0;i<N;i++)
       {

              if(hash_func[i]->isempty()) continue;
              hash_func[i]->goto_head();

              while(if_this_elem_is_good_without_hash(hash_func[i]->get_curr()))
              {
                   hash_func[i]->del_head();
                   if(hash_func[i]->isempty()) break;
              }

              for(;hash_func[i]->get_curr();)
              {
                  if(!hash_func[i]->get_curr()->get_next()) break;

                  if(if_this_elem_is_good_without_hash(hash_func[i]->get_curr()->get_next()))
                  {
                       hash_func[i]->del_next();
                  }
                  else
                  {
                       hash_func[i]->goto_next();
                  }
              }

              hash_func[i]->goto_next();
       }
}

void command::delete_with_hash(record_list** hash_func, int N)
{
    int i,k;

    k = hash_(name, N);

    switch (c_name)
    {
        case (COND_EQ):
        {

            if(hash_func[k]->isempty()) break;

            for(hash_func[k]->goto_head(); hash_func[k]->get_curr();)
            {

               while(if_this_elem_is_good_with_hash(hash_func[k]->get_curr()))
               {
                   hash_func[k]->del_head();
                   if(hash_func[k]->isempty()) break;
               }

               for(;hash_func[k]->get_curr();)
               {
                   if(!hash_func[k]->get_curr()->get_next()) break;

                   if(if_this_elem_is_good_with_hash(hash_func[k]->get_curr()->get_next()))
                   {
                       hash_func[k]->del_next();
                   }
                   else
                   {
                       hash_func[k]->goto_next();
                   }
               }

               hash_func[k]->goto_next();
            }
            break;
        }

        case (COND_NE):
        {
             for(i=0;i<N;i++)
             {

                if(k==i) continue;
                if(hash_func[i]->isempty()) continue;

                for(hash_func[i]->goto_head(); hash_func[i]->get_curr();)
                {
                   if(hash_func[i]->isempty()) continue;
                   hash_func[i]->goto_head();

                   while(if_this_elem_is_good_with_hash(hash_func[i]->get_curr()))
                   {
                       hash_func[i]->del_head();
                       if(hash_func[i]->isempty()) break;
                   }

                   for(;hash_func[i]->get_curr();)
                   {
                      if(!hash_func[i]->get_curr()->get_next()) break;

                      if(if_this_elem_is_good_with_hash(hash_func[i]->get_curr()->get_next()))
                      {
                           hash_func[i]->del_next();
                      }
                      else
                      {
                           hash_func[i]->goto_next();
                      }
                   }

                   hash_func[i]->goto_next();
                }
             }

             break;
        }

        case (COND_GT):
        {
             for(i=k;i<N;i++)
             {

                    if(hash_func[i]->isempty()) continue;

                    for(hash_func[i]->goto_head(); hash_func[i]->get_curr();)
                    {
                      if(hash_func[i]->isempty()) continue;
                      hash_func[i]->goto_head();

                      while(if_this_elem_is_good_with_hash(hash_func[i]->get_curr()))
                      {
                         hash_func[i]->del_head();
                         if(hash_func[i]->isempty()) break;
                      }

                      for(;hash_func[i]->get_curr();)
                      {
                         if(!hash_func[i]->get_curr()->get_next()) break;

                         if(if_this_elem_is_good_with_hash(hash_func[i]->get_curr()->get_next()))
                         {
                            hash_func[i]->del_next();
                         }
                         else
                         {
                            hash_func[i]->goto_next();
                         }
                      }

                      hash_func[i]->goto_next();
                    }

             }

             break;
        }

        case (COND_LT):
        {
             for(i=0;i<=k;i++)
             {

                    if(hash_func[i]->isempty()) continue;

                    for(hash_func[i]->goto_head(); hash_func[i]->get_curr();)
                    {
                       while(if_this_elem_is_good_with_hash(hash_func[i]->get_curr()))
                       {
                           hash_func[i]->del_head();
                           if(hash_func[i]->isempty()) break;
                       }

                       for(;hash_func[i]->get_curr();)
                       {
                          if(!hash_func[i]->get_curr()->get_next()) break;

                          if(if_this_elem_is_good_with_hash(hash_func[i]->get_curr()->get_next()))
                          {
                               hash_func[i]->del_next();
                          }
                          else
                          {
                               hash_func[i]->goto_next();
                          }
                       }

                       hash_func[i]->goto_next();
                    }

             }
             break;
        }


        case (COND_LE):
        {
             for(i=0;i<=k;i++)
             {

                    if(hash_func[i]->isempty()) continue;

                    for(hash_func[i]->goto_head(); hash_func[i]->get_curr();)
                    {
                       if(hash_func[i]->isempty()) continue;
                       hash_func[i]->goto_head();

                       while(if_this_elem_is_good_with_hash(hash_func[i]->get_curr()))
                       {
                           hash_func[i]->del_head();
                           if(hash_func[i]->isempty()) break;
                       }

                       for(;hash_func[i]->get_curr();)
                       {
                          if(!hash_func[i]->get_curr()->get_next()) break;

                          if(if_this_elem_is_good_with_hash(hash_func[i]->get_curr()->get_next()))
                          {
                               hash_func[i]->del_next();
                          }
                          else
                          {
                               hash_func[i]->goto_next();
                          }
                       }

                       hash_func[i]->goto_next();
                    }

             }
             break;
        }

        case (COND_GE):
        {
             for(i=k;i<N;i++)
             {

                    if(hash_func[i]->isempty()) continue;

                    for(hash_func[i]->goto_head(); hash_func[i]->get_curr();)
                    {
                       if(hash_func[i]->isempty()) continue;
                       hash_func[i]->goto_head();

                       while(if_this_elem_is_good_with_hash(hash_func[i]->get_curr()))
                       {
                           hash_func[i]->del_head();
                           if(hash_func[i]->isempty()) break;
                       }

                       for(;hash_func[i]->get_curr();)
                       {
                          if(!hash_func[i]->get_curr()->get_next()) break;

                          if(if_this_elem_is_good_with_hash(hash_func[i]->get_curr()->get_next()))
                          {
                               hash_func[i]->del_next();
                          }
                          else
                          {
                               hash_func[i]->goto_next();
                          }
                       }

                       hash_func[i]->goto_next();
                    }

             }

             break;
        }

        case (COND_NONE):
        {
           return;
        }

    }
}


void command::select_with_hash(record_list** hash_func, int N)
{
    int i,k;

    k = hash_(name, N);

    switch (c_name)
    {
        case (COND_EQ):
        {
            if(hash_func[k]->isempty()) break;

            for(hash_func[k]->goto_head(); hash_func[k]->get_curr();)
            {
                if(if_this_elem_is_good_with_hash(hash_func[k]->get_curr()))
                {
                    print_good_elements(hash_func[k]->get_curr());
                }

                hash_func[k]->goto_next();
            }
            break;
        }

        case (COND_NE):
        {
             for(i=0;i<N;i++)
             {
                if(k==i) continue;
                if(hash_func[k]->isempty()) continue;

                for(hash_func[i]->goto_head(); hash_func[i]->get_curr();)
                {
                    if(if_this_elem_is_good_with_hash(hash_func[i]->get_curr()))
                    {
                        print_good_elements(hash_func[i]->get_curr());
                    }

                    hash_func[i]->goto_next();
                }
             }

             break;
        }

        case (COND_GT):
        {
             for(i=k;i<N;i++)
             {

                if(hash_func[i]->isempty()) continue;

                for(hash_func[i]->goto_head(); hash_func[i]->get_curr();)
                {
                    if(if_this_elem_is_good_with_hash(hash_func[i]->get_curr()))
                    {
                        print_good_elements(hash_func[i]->get_curr());
                    }

                    hash_func[i]->goto_next();
                }

             }

             break;
        }

        case (COND_LT):
        {
             for(i=0;i<=k;i++)
             {

                if(hash_func[i]->isempty()) continue;

                for(hash_func[i]->goto_head(); hash_func[i]->get_curr();)
                {
                    if(if_this_elem_is_good_with_hash(hash_func[i]->get_curr()))
                    {
                        print_good_elements(hash_func[i]->get_curr());
                    }

                    hash_func[i]->goto_next();
                }

             }
             break;
        }


        case (COND_LE):
        {
             for(i=0;i<=k;i++)
             {

                if(hash_func[i]->isempty()) continue;


                for(hash_func[i]->goto_head(); hash_func[i]->get_curr();)
                {
                    if(if_this_elem_is_good_with_hash(hash_func[i]->get_curr()))
                    {
                        print_good_elements(hash_func[i]->get_curr());
                    }

                    hash_func[i]->goto_next();
                }

             }
             break;
        }

        case (COND_GE):
        {
             for(i=k;i<N;i++)
             {
                if(hash_func[i]->isempty()) continue;

                for(hash_func[i]->goto_head(); hash_func[i]->get_curr();)
                {
                    if(if_this_elem_is_good_with_hash(hash_func[i]->get_curr()))
                    {
                        print_good_elements(hash_func[i]->get_curr());
                    }

                    hash_func[i]->goto_next();
                }

             }

             break;
        }

        case (COND_NONE):
        {
           return;
        }

    }
}

int command::apply(record_list** hash_func, int N)
{

   switch (type)
   {

      case (CMD_QUIT):
          {
              printf("FUCK ALL");
              return -2;
          }


      case (CMD_NONE):
          {
              return 0;
          }


      case (CMD_INSERT):
          {
              record_node *p=0;
              p=new record_node(name,phone,group);

              int k;

              k = hash_(name, N);

              hash_func[k]->add_head(p);
              break;
          }

      case (CMD_SELECT):
          {
              printf("\nSELECTED: \n");

              if(if_there_name() && (operation!=OP_OR))
              {
                 select_with_hash(hash_func, N);
              }
              else
              {
                 select_without_hash(hash_func, N);
              }

              return -1;
          }

      case (CMD_DELETE):
          {

              if(if_there_name() && (operation!=OP_OR))
              {
                 delete_with_hash(hash_func, N);
              }
              else
              {
                 delete_without_hash(hash_func, N);
              }

              return 0;
          }

   }

   return 0;
}

int command::init_str(const char* str)
{
    int i,k;

    char **words = new char*[10];
    const char *t;

    for(i=0;i<9;i++)
    {
        words[i] = new char[10];
        strcpy( words[i], "" );
    }

    t = " ();.,\n";

    k = func_words(str,t,words);

    type = CMD_NONE;
    c_name = COND_NONE;
    c_phone = COND_NONE;
    c_group = COND_NONE;
    operation = OP_NONE;

    if(strcmp(words[0],"quit")==0)
    {
       type = CMD_QUIT;

       for(i=0;i<9;i++)
       {
           delete [] words[i];
       }

       delete [] words;

       return 0;
    }

    if(strcmp(words[0],"insert")==0)
    {
        type = CMD_INSERT;
        c_name = COND_NONE;
        c_phone = COND_NONE;
        c_group = COND_NONE;
        operation = OP_NONE;

        name = words[1];
        phone = atoi(words[2]);
        group = atoi(words[3]);
    }

    if( (strcmp(words[0],"select")==0) || (strcmp(words[0],"delete")==0) )
    {

        switch (words[2][0])
        {
            case ('n'):
            {
               switch (words[3][0])
               {
                  case ('='): { c_name = COND_EQ; break; }
                  case ('<'):
                     {
                          if(words[3][1]=='=')
                          {
                            c_name = COND_LE;
                            break;
                          }
                          else
                          {
                              if(words[3][1]=='>')
                              {
                                c_name = COND_NE;
                                break;
                              }
                              else
                              {
                                  c_name = COND_LT;
                                  break;
                              }
                          }
                     }
                  case ('>'):
                     {
                          if(words[3][1]=='=')
                          {
                            c_name = COND_GE;
                            break;
                          }
                          else
                          {
                              c_name = COND_GT;
                              break;
                          }
                     }
               }
               name = words[4];
               break;
            }

            case ('g'):
            {
               switch (words[3][0])
               {
                  case ('='): { c_group =  COND_EQ; break; }
                  case ('<'):
                    {
                          if(words[3][1]=='=')
                          {
                            c_group = COND_LE;
                            break;
                          }
                          else
                          {
                              if(words[3][1]=='>')
                              {
                                c_group = COND_NE;
                                break;
                              }
                              else
                              {
                                  c_group = COND_LT;
                                  break;
                              }
                          }
                    }
                  case ('>'):
                     {
                          if(words[3][1]=='=')
                          {
                            c_group = COND_GE;
                            break;
                          }
                          else
                          {
                              c_group = COND_GT;
                              break;
                          }
                     }

               }
               group = atoi(words[4]);
               break;
            }

            case ('p'):
            {
               switch (words[3][0])
               {
                  case ('='): { c_phone = COND_EQ; break; }
                  case ('<'):
                      {
                          if(words[3][1]=='=')
                          {
                            c_phone = COND_LE;
                            break;
                          }
                          else
                          {
                              if(words[3][1]=='>')
                              {
                                c_phone = COND_NE;
                                break;
                              }
                              else
                              {
                                  c_phone = COND_LT;
                                  break;
                              }
                          }
                      }
                  case ('>'):
                     {
                          if(words[3][1]=='=')
                          {
                             c_phone = COND_GE;
                             break;
                          }
                          else
                          {
                              c_phone = COND_GT;
                              break;
                          }
                     }

               }
               phone = atoi(words[4]);
               break;
            }

        }

        if(k>5)
        {
            if(strcmp(words[5],"and")==0) operation = OP_AND;
            else operation = OP_OR;

            switch (words[6][0])
            {
                case ('n'):
                {
                   switch (words[7][0])
                   {
                     case ('='): { c_name = COND_EQ; break; }
                     case ('<'):
                     {
                          if(words[7][1]=='=')
                          {
                            c_name = COND_LE;
                            break;
                          }
                          else
                          {
                              if(words[7][1]=='>')
                              {
                                c_name = COND_NE;
                                break;
                              }
                              else
                              {
                                  c_name = COND_LT;
                                  break;
                              }
                          }
                     }
                     case ('>'):
                     {
                          if(words[7][1]=='=')
                          {
                             c_name = COND_GE;
                             break;
                          }
                          else
                          {
                              c_name = COND_GT;
                              break;
                          }
                     }
                   }
                   name = words[8];
                   break;
                }

                case ('g'):
                {
                   switch (words[7][0])
                   {
                      case ('='): { c_group =  COND_EQ; break; }
                      case ('<'):
                      {
                          if(words[7][1]=='=')
                          {
                            c_group = COND_LE;
                            break;
                          }
                          else
                          {
                              if(words[7][1]=='>')
                              {
                                c_group = COND_NE;
                                break;
                              }
                              else
                              {
                                  c_group = COND_LT;
                                  break;
                              }
                          }
                      }
                      case ('>'):
                      {
                          if(words[7][1]=='=')
                          {
                            c_group = COND_GE;
                            break;
                          }
                          else
                          {
                              c_group = COND_GT;
                              break;
                          }
                      }

                   }
                   group = atoi(words[8]);
                   break;
                }

                case ('p'):
                {
                   switch (words[7][0])
                   {
                     case ('='): { c_phone = COND_EQ; break; }
                     case ('<'):
                     {
                          if(words[7][1]=='=')
                          {
                              c_phone = COND_LE;
                              break;
                          }
                          else
                          {
                              if(words[7][1]=='>')
                              {
                                 c_phone = COND_NE;
                                 break;
                              }
                              else
                              {
                                  c_phone = COND_LT;
                                  break;
                              }
                          }
                     }
                     case ('>'):
                     {
                          if(words[7][1]=='=')
                          {
                             c_phone = COND_GE;
                             break;
                          }
                          else
                          {
                              c_phone = COND_GT;
                              break;
                          }
                     }

                   }
                   phone = atoi(words[8]);
                   break;
                }

            }

        }
        else operation = OP_NONE;
    }

    if(strcmp(words[0],"select")==0) type = CMD_SELECT;
    if(strcmp(words[0],"delete")==0) type = CMD_DELETE;

    if(strcmp(name,"")!=0)
    {
        for(i=0;name;i++)
        {
          if(name[i]=='\n')
          {
             name[i]= '\0';
             break;
          }
        }
    }

    for(i=0;i<9;i++)
    {
        delete [] words[i];
    }

    delete [] words;


    return 0;
}

int func_words(const char* str, const char* t, char**words)
{
    int  k, i, flag, n;

    flag=0;
    char buf[LEN];
    char bufchr[1];

    strcpy(buf, str);

    n = strlen(str);

    k=-1;

    for(i=0;i<n;i++)
    {
        if( strchr(t,str[i]) )
        {
            buf[i] = '\n';
            flag = 0;
        }
        else
        {
            if(flag==0)
            {
                flag = 1;
                k++;
                bufchr[0] = str[i];
                strncat(words[k], bufchr, 1);
            }
            else
            {
               bufchr[0] = str[i];
               strncat(words[k], bufchr, 1);
            }
        }
    }

    return k+1;
}
