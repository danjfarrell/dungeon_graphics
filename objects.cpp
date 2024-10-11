#include "objects.h"
#include "core_engine.h"

Objects::Objects()
{
       
        //Object temp_object;
        int n;
        //int numb_objects,n,o_type, os_type,color, num_strings, item_index;
        //char symbol;
        char new_str[UI_MESSAGE_MAX_SIZE];
        char str[200];
        char str2[200];
        //char str4[200];
        //char str3[200];
        std::string s;

        //n = sprintf(str4, "gamedata/resources/object_data_v2_out_number.txt");
        //FILE* outfile_file = fopen(str4, "w");

        n = sprintf(str2, "gamedata/resources/object_data_v2.txt");
        FILE* resource_file_2 = fopen(str2, "r");
        n=fscanf(resource_file_2, "%s\n", &str);
        s.append(str);
        printf("got chars\n");
        for (unsigned int i = 0; i < s.length(); i++)
        {
            object_character.push_back(s[i]);
        }
        printf("got chars loaded\n");
        s.clear();
        //while (fscanf(resource_file_2, "%s", str2) != EOF )
        while (fgets(new_str, UI_MESSAGE_MAX_SIZE, resource_file_2))
        {
            //printf("got name: %d %s\n", sizeof(new_str), new_str);
            new_str[strcspn(new_str, "\n")] = '\0';
            strcpy(str2, new_str);
            //printf("got name: %s\n", str2);
            s.append(str2);
            object_names.push_back(s);
            //fprintf(outfile_file, "%d,%s\n", object_names.size(), str2);
            s.clear();
        }
        fclose(resource_file_2);
        //fclose(outfile_file);
        
        //contains colors
        n = sprintf(str2, "gamedata/resources/object_data.txt");
        FILE* resource_file = fopen(str2, "r");
        const unsigned MAX_LENGTH = 256;
        char buffer[MAX_LENGTH];
        const char split[2] = ",";
        char* token;
        std::vector<std::string>  tokens_elements;

        while (fgets(buffer, MAX_LENGTH, resource_file))
        {
            
            token = strtok(buffer, split);
            while (token != NULL)
            {
                printf("%s\n", token);
                tokens_elements.push_back(token);
                token = strtok(NULL, split);
            }
            printf("objects tokens_elements.size() = %i\n", tokens_elements.size());
            if (tokens_elements.size() == 4)
            {
                SDL_Color temp_color;
                //strcpy(temp_element.element, tokens_elements[0].c_str());

                temp_color.b = atoi(tokens_elements[0].c_str());
                temp_color.g = atoi(tokens_elements[1].c_str());
                temp_color.r = atoi(tokens_elements[2].c_str());
                object_color.push_back(temp_color);
                object_font.push_back(atoi(tokens_elements[3].c_str()));
            }

            tokens_elements.clear();

        }
        fclose(resource_file);
        



}


