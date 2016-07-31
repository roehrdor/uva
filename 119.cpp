#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>

typedef struct
{
    char name[0xF];
    int debit;
} person_t;

person_t persons[10];

int main(int argc, char const *argv[])
{
    person_t* person;
    std::map<std::string, person_t*> persons_links;
    char line[0xFF];
    int num_persons;
    char *p, *p2;
    int i, amount, num_gifted_persons, amount_per_person;
    int counter;

    counter = 0;

    while(fgets(line, 0xFF, stdin))
    {
        persons_links.clear();
        memset(persons, 0, sizeof(person_t) * 10);
        num_persons = atoi(line);
        if(num_persons == 0) {
            printf("\n");
            continue;
        }
        if(!fgets(line, 0xFF, stdin))
            return 1;
        if(++counter > 1)
            printf("\n");
        i = 0;
        p = strtok(line, " ");
        if(p[strlen(p) - 1] == '\n')
            p[strlen(p) - 1] = '\0';
        strcpy(persons[i].name, p);
        persons_links.insert(std::pair<std::string, person_t*>(std::string(p), &persons[i]));
        while((p = strtok(NULL, " ")) != NULL)
        {
            if(p[strlen(p) - 1] == '\n')
                p[strlen(p) - 1] = '\0';
            strcpy(persons[++i].name, p);
            persons_links.insert(std::pair<std::string, person_t*>(std::string(p), &persons[i]));
        }
        i = num_persons;
        while(i--)
        {
            if(!fgets(line, 0xFF, stdin))
                return 1;
            p = &line[0];
            while(*p && *p != ' ')   ++p;
            *p = '\0'; ++p;

            person = persons_links.find(std::string(line))->second;
            amount = atoi(p);

            if(amount == 0)
                continue;

            while(*p && *p != ' ')   ++p;
            *p = '\0'; ++p;
            num_gifted_persons = atoi(p);

            if(num_gifted_persons == 0)
                continue;

            amount_per_person = amount / num_gifted_persons;
            person->debit -= amount_per_person * num_gifted_persons;
            while(*p && *p != ' ')   ++p;
            *p = '\0'; ++p;

            while(num_gifted_persons-- > 0)
            {
                p2 = p;
                while(*p && *p != ' ' && *p != '\n')   ++p;
                *p = '\0'; ++p;
                persons_links.find(std::string(p2))->second->debit += amount_per_person;
            }
        }
        for(i = 0; i < num_persons; ++i)
            printf("%s %d\n", persons[i].name, persons[i].debit);
    }


    return 0;
}
