//
//  main.c
//  MailSearch
//
//  Created by Karthik Ragunath A on 05/06/17.
//  Copyright © 2017 Karthik Ragunath A. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    char a;
    int length;
    char *string;
    string=(char *)malloc(400*sizeof(char));
    fp=fopen("karthik.txt","r");
    int m=0;
    if(fp==NULL)
    {
        printf("File is not read");
        return 0;
    }
    else
    {
        printf("The file contains :");
        while(!feof(fp))
        {
            fscanf(fp,"%c",&a);
            printf("%c",a);
            string[m++]=a;
        }
        printf("\n");
    }
    length=m;

    int i,j,k,l;
    int subject = 0;
    int date = 0;
    int from = 0;
    int to = 0;
    int mailStarting = 0;
    int flagship;
    int dateFlagship;
    int fromFlagship;
    int toFlagship;
    int *mailStartingPositionArray = (int *)calloc(1, sizeof(int));
    int mailNumberNow = 0;
    char **subjectSearch;
    subjectSearch = (char **)calloc(15, sizeof(char *));
    for(int n = 0; n < 15; n++)
    {
        subjectSearch[n] = (char *)calloc(100, sizeof(char));
    }
    char **fromSearch;
    fromSearch = (char **)calloc(15, sizeof(char *));
    for(int n = 0; n < 15; n++)
    {
        fromSearch[n] = (char *)calloc(100, sizeof(char));
    }
    char **toSearch;
    toSearch = (char **)calloc(15, sizeof(char *));
    for(int n = 0; n < 15; n++)
    {
        toSearch[n] = (char *)calloc(100, sizeof(char));
    }

    char *tempSubject = (char *)calloc(100, sizeof(char));
    char *tempFrom = (char *)calloc(100, sizeof(char));
    char *tempTo = (char *)calloc(100, sizeof(char));
    int indexSub;
    int indexFrom;
    int indexTo;

    for(k = 0; k < length; k++)
    {
        if(subject == 0)
        {
            indexSub = 0;
            flagship = 1;
            for(i = k, j = k, l = 0; i < (k + 8) && j < length; i++, j++, l++)
            {
                switch (l)
                {
                    case 0:
                        if(string[i] != 'S')
                        {
                            flagship = 0;
                        }
                        break;
                    case 1:
                        if(string[i] != 'u')
                        {
                            flagship = 0;
                        }
                        break;
                    case 2:
                        if(string[i] != 'b')
                        {
                            flagship = 0;
                        }
                        break;
                    case 3:
                        if(string[i] != 'j')
                        {
                            flagship = 0;
                        }
                        break;
                    case 4:
                        if(string[i] != 'e')
                        {
                            flagship = 0;
                        }
                        break;
                    case 5:
                        if(string[i] != 'c')
                        {
                            flagship = 0;
                        }
                        break;
                    case 6:
                        if(string[i] != 't')
                        {
                            flagship = 0;
                        }
                        break;
                    case 7:
                        if(string[i] != ':')
                        {
                            flagship = 0;
                        }
                        break;
                    default:
                        break;
                }
                if(flagship == 0)
                {
                    break;
                }
            }
            if(flagship == 1)
            {
                subject = 1;
                mailStarting = k;
                k = k + 7;
                tempSubject = calloc(100, sizeof(char));
                for(; k < length; k++)
                {
                    if(string[k] == '\n')
                    {
                        tempSubject[indexSub++] = '\0';
                        break;
                    }
                    else
                    {
                        tempSubject[indexSub++] = string[k];
                    }
                }
            }
            else
            {
                tempSubject = calloc(100, sizeof(char));
                for(; k < length; k++)
                {
                    if(string[k] == '\n')
                    {
                        break;
                    }
                }
            }
        }
        else
        {
            if(date == 0)
            {
                dateFlagship = 1;
                for(i = k, j = k, l = 0; i < (k + 5) && j < length; i++, j++, l++)
                {
                    switch (l)
                    {
                        case 0:
                            if(string[i] != 'D')
                            {
                                dateFlagship = 0;
                            }
                            break;

                        case 1:
                            if(string[i] != 'a')
                            {
                                dateFlagship = 0;
                            }
                            break;

                        case 2:
                            if(string[i] != 't')
                            {
                                dateFlagship = 0;
                            }
                            break;

                        case 3:
                            if(string[i] != 'e')
                            {
                                dateFlagship = 0;
                            }
                            break;

                        case 4:
                            if(string[i] != ':')
                            {
                                dateFlagship = 0;
                            }
                            break;

                        default:
                            break;
                    }
                    if(dateFlagship == 0)
                    {
                        break;
                    }
                }
                if(dateFlagship == 1)
                {
                    k = k + 4;
                    date = 1;
                    for(; k < length; k++)
                    {
                        if(string[k] == '\n')
                        {
                            break;
                        }
                    }
                }
                else
                {
                    subject = 0;
                    mailStarting = 0;
                    date = 0;
                    tempSubject = calloc(100, sizeof(char));
                    for(; k < length; k++)
                    {
                        if(string[k] == '\n')
                        {
                            break;
                        }
                    }
                }
            }
            else
            {
                if(from == 0)
                {
                    indexFrom = 0;
                    fromFlagship = 1;
                    for(i = k, j = k, l = 0; i < (k + 4) && j < length; i++, j++, l++)
                    {
                        switch (l)
                        {
                            case 0:
                                if(string[i] != 'F')
                                {
                                    fromFlagship = 0;
                                }
                                break;

                            case 1:
                                if(string[i] != 'r')
                                {
                                    fromFlagship = 0;
                                }
                                break;

                            case 2:
                                if(string[i] != 'o')
                                {
                                    fromFlagship = 0;
                                }
                                break;

                            case 3:
                                if(string[i] != 'm')
                                {
                                    fromFlagship = 0;
                                }
                                break;

                            case 4:
                                if(string[i] != ':')
                                {
                                    fromFlagship = 0;
                                }
                                break;

                            default:
                                break;
                        }
                        if(fromFlagship == 0)
                        {
                            break;
                        }
                    }
                    if(fromFlagship == 1)
                    {
                        k = k + 4;
                        from = 1;
                        tempFrom = calloc(100, sizeof(char));
                        for(; k < length; k++)
                        {
                            if(string[k] == '\n')
                            {
                                tempFrom[indexFrom++] = '\0';
                                break;
                            }
                            else
                            {
                                tempFrom[indexFrom++] = string[k];
                            }
                        }
                    }
                    else
                    {
                        subject = 0;
                        date = 0;
                        from = 0;
                        mailStarting = 0;
                        tempFrom = calloc(100, sizeof(char));
                        tempSubject = calloc(100, sizeof(char));
                        for(; k < length; k++)
                        {
                            if(string[k] == '\n')
                            {
                                break;
                            }
                        }
                    }
                }
                else
                {
                    if(to == 0)
                    {
                        indexTo = 0;
                        toFlagship = 1;
                        for(i = k, j = k, l = 0; i < (k + 3) && j < length; i++, j++, l++)
                        {
                            switch (l)
                            {
                                case 0:
                                    if(string[i] != 'T')
                                    {
                                        toFlagship = 0;
                                    }
                                    break;

                                case 1:
                                    if(string[i] != 'o')
                                    {
                                        toFlagship = 0;
                                    }
                                    break;

                                case 2:
                                    if(string[i] != ':')
                                    {
                                        toFlagship = 0;
                                    }
                                    break;

                                default:
                                    break;
                            }
                            if(toFlagship == 0)
                            {
                                break;
                            }
                        }
                        if(toFlagship == 1)
                        {
                            k = k + 2;
                            to = 1;
                            mailStartingPositionArray[mailNumberNow] = mailStarting;
                            mailNumberNow = mailNumberNow + 1;
                            mailStartingPositionArray = (int *)realloc(mailStartingPositionArray, mailNumberNow * sizeof(int));
                            subject = 0;
                            date = 0;
                            from = 0;
                            to = 0;
                            mailStarting = 0;
                            tempTo = calloc(50, sizeof(char));
                            for(; k < length; k++)
                            {
                                if(string[k] == '\n')
                                {
                                    tempTo[indexTo++] = '\0';
                                    break;
                                }
                                else
                                {
                                    tempTo[indexTo++] = string[k];
                                }
                            }
                            strcpy(subjectSearch[mailNumberNow - 1], tempSubject);
                            strcpy(fromSearch[mailNumberNow - 1], tempFrom);
                            strcpy(toSearch[mailNumberNow - 1], tempTo);
                        }
                        else
                        {
                            subject = 0;
                            date = 0;
                            from = 0;
                            to = 0;
                            mailStarting = 0;
                            tempFrom = calloc(100, sizeof(char));
                            tempSubject = calloc(100, sizeof(char));
                            tempTo = calloc(100, sizeof(char));
                            for(; k < length; k++)
                            {
                                if(string[k] == '\n')
                                {
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    for(int v = 0; v < mailNumberNow; v++)
    {
        int subjectLength = strlen(subjectSearch[v]);
        int fromLength = strlen(fromSearch[v]);
        int toLength = strlen(toSearch[v]);

        for(int x = 0; x < subjectLength; x++)
        {
            printf("%c", subjectSearch[v][x]);
        }
        printf("\n");
        for (int x = 0; x < fromLength; x++)
        {
            printf("%c", fromSearch[v][x]);
        }
        printf("\n");
        for (int x = 0; x < toLength; x++)
        {
            printf("%c", toSearch[v][x]);
        }
        printf("\n");
        printf("\n");
    }

    printf("Enter the subject to searach for: \n");
    char *subjectString = (char *)calloc(50, sizeof(char));
    scanf("%[^\n]%*c", subjectString);

    printf("Enter the mailId to search for: \n");
    char *mailIdString = (char *)calloc(50, sizeof(char));
    scanf("%s", mailIdString);

    int solution = 234230;
    for (int v = 0; v < mailNumberNow; v++)
    {
        int subjectSatisfied = 0;
        int mailSatisfied = 0;
        //        int subjectLength = strlen(subjectSearch[v]);
        //        int fromLength = strlen(fromSearch[v]);
        //        int toLength = strlen(toSearch[v]);

        if(strstr(subjectSearch[v], subjectString) != NULL)
        {
            subjectSatisfied = 1;
        }
        if((strstr(fromSearch[v], mailIdString) != NULL) || (strstr(toSearch[v], mailIdString) != NULL))
        {
            mailSatisfied = 1;
        }
        if(subjectSatisfied == 1 && mailSatisfied == 1)
        {
            solution = v;
            break;
        }
    }

    if(solution < (mailNumberNow -1))
    {
        int solutionStartingPosition = mailStartingPositionArray[solution];
        int solutionEndingPosition = mailStartingPositionArray[solution + 1];
        printf("The mail to be displayed is: \n");
        for(int y = solutionStartingPosition; y < solutionEndingPosition; y++)
        {
            printf("%c", string[y]);
        }
    }
    else if(solution == (mailNumberNow - 1))
    {
        int solutionStartingPosition = mailStartingPositionArray[solution];
        int solutionEndingPosition = length;
        printf("The mail to be displayed is: \n");
        for(int y = solutionStartingPosition; y < solutionEndingPosition; y++)
        {
            printf("%c", string[y]);
        }
    }
    else
    {
        printf("No Solution");
    }

    return 0;
}
