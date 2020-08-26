#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void Proposition_Array(char *expression, char *proposition)
{
    int i, j, equal = 0, n = 0;
    int num_of_characters = 0;

    for (i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] >= 65 && expression[i] <= 90)
        {
            equal = 0;
            for (j = 0; proposition[j] != '\0'; j++)
            {
                if (expression[i] == proposition[j])
                    equal++;
            }
            if (equal == 0)
            {
                proposition[n] = expression[i];
                n++;
            }
        }
    }
    proposition[n] = '\0';
}

char *Unidimensional_Matrix_Malloc(int Lines)
{
    char *MatrixName = malloc(Lines * sizeof(char));

    return MatrixName;
}

char **Bidimensional_Matrix_Calloc(int Lines, int columns)
{
    int i = 0;

    char **MatrixName = (char **)calloc(Lines, sizeof(char *));

    for (i = 0; i < Lines; i++)
    {
        MatrixName[i] = (char *)calloc(columns, sizeof(char));
    }

    return MatrixName;
}

char *Matrix_Organizer(int matrix_size, char *expression)
{
    char *organized_matrix = malloc(matrix_size * sizeof(char));
    int i, j;
    for (i = 0, j = 0; i < matrix_size; i++, j++)
    {
        if (expression[i] == '-')
        {
            i = i + 1;
            organized_matrix[j] = '>';
        }
        if (expression[i] == '<')
        {
            i = i + 2;
            organized_matrix[j] = '<';
        }
        else
        {
            organized_matrix[j] = expression[i];
        }
    }
    organized_matrix[j] = '\0';
    return organized_matrix;
}

int Characters_Counter(int matrix_sizeofString, char *term)
{
    int i, j, counter, times;
    int num_of_characters = 0;

    for (i = 0; i < matrix_sizeofString; i++)
    {
        if (term[i] >= 65 && term[i] <= 90)
        {
            counter = 1;
            times = 0;
            for (j = i; j >= 0; j--)
            {
                if (term[i] != term[j])
                {
                    counter++;
                }

                times++;
            }
            if (counter == times)
                num_of_characters++;
        }
    }

    return num_of_characters;
}

void Operation_Not(char *expression)
{
    int i;
    for (i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] == '~')
        {
            if (expression[i + 1] == '1')
            {
                expression[i] = ' ';
                expression[i + 1] = '0';
            }
            else if (expression[i + 1] == '0')
            {
                expression[i] = ' ';
                expression[i + 1] = '1';
            }
        }
    }
}

void Operations_1(char *expression)
{
    int i, j;

    for (i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] == '0' || expression[i] == '1')
        {
            if (expression[i + 2] == '0' || expression[i + 2] == '1')
            {
                if (expression[i + 1] == 'v')
                {
                    if (expression[i] == '0' && expression[i + 2] == '0')
                    {
                        expression[i] = ' ';
                        expression[i + 1] = '0';
                        expression[i + 2] = ' ';
                    }
                    if (expression[i] == '1' && expression[i + 2] == '0')
                    {
                        expression[i] = ' ';
                        expression[i + 1] = '1';
                        expression[i + 2] = ' ';
                    }
                    if (expression[i] == '0' && expression[i + 2] == '1')
                    {
                        expression[i] = ' ';
                        expression[i + 1] = '1';
                        expression[i + 2] = ' ';
                    }
                    if (expression[i] == '1' && expression[i + 2] == '1')
                    {
                        expression[i] = ' ';
                        expression[i + 1] = '1';
                        expression[i + 2] = ' ';
                    }
                }

                if (expression[i + 1] == '^')
                {
                    if (expression[i] == '0' && expression[i + 2] == '0')
                    {
                        expression[i] = ' ';
                        expression[i + 1] = '0';
                        expression[i + 2] = ' ';
                    }
                    if (expression[i] == '1' && expression[i + 2] == '0')
                    {
                        expression[i] = ' ';
                        expression[i + 1] = '0';
                        expression[i + 2] = ' ';
                    }
                    if (expression[i] == '0' && expression[i + 2] == '1')
                    {
                        expression[i] = ' ';
                        expression[i + 1] = '0';
                        expression[i + 2] = ' ';
                    }
                    if (expression[i] == '1' && expression[i + 2] == '1')
                    {
                        expression[i] = ' ';
                        expression[i + 1] = '1';
                        expression[i + 2] = ' ';
                    }
                }
            }
        }
        if (expression[i] == '~')
        {
            if (expression[i + 1] == '1')
            {
                expression[i] = ' ';
                expression[i + 1] = '0';
            }
            else if (expression[i + 1] == '0')
            {
                expression[i] = ' ';
                expression[i + 1] = '1';
            }
        }
    }
}

void Operations_2(char *expression, int matrix_size)
{
    int i, j;

    for (i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] == '0' || expression[i] == '1')
        {
            if (expression[i + 2] == '0' || expression[i + 2] == '1')
            {
                if (expression[i + 1] == '>')
                {
                    if (expression[i] == '0' && expression[i + 2] == '0')
                    {
                        expression[i] = ' ';
                        expression[i + 1] = '1';
                        expression[i + 2] = ' ';
                    }
                    if (expression[i] == '1' && expression[i + 2] == '0')
                    {
                        expression[i] = ' ';
                        expression[i + 1] = '0';
                        expression[i + 2] = ' ';
                    }
                    if (expression[i] == '0' && expression[i + 2] == '1')
                    {
                        expression[i] = ' ';
                        expression[i + 1] = '1';
                        expression[i + 2] = ' ';
                    }
                    if (expression[i] == '1' && expression[i + 2] == '1')
                    {
                        expression[i] = ' ';
                        expression[i + 1] = '1';
                        expression[i + 2] = ' ';
                    }
                }

                if (expression[i + 1] == '<')
                {
                    if (expression[i] == '0' && expression[i + 2] == '0')
                    {
                        expression[i] = ' ';
                        expression[i + 1] = '1';
                        expression[i + 2] = ' ';
                    }
                    if (expression[i] == '1' && expression[i + 2] == '0')
                    {
                        expression[i] = ' ';
                        expression[i + 1] = '0';
                        expression[i + 2] = ' ';
                    }
                    if (expression[i] == '0' && expression[i + 2] == '1')
                    {
                        expression[i] = ' ';
                        expression[i + 1] = '0';
                        expression[i + 2] = ' ';
                    }
                    if (expression[i] == '1' && expression[i + 2] == '1')
                    {
                        expression[i] = ' ';
                        expression[i + 1] = '1';
                        expression[i + 2] = ' ';
                    }
                }

                if (expression[i + 1] == '#')
                {
                    if (expression[i] == '0' && expression[i + 2] == '0')
                    {
                        expression[i] = ' ';
                        expression[i + 1] = '0';
                        expression[i + 2] = ' ';
                    }
                    if (expression[i] == '1' && expression[i + 2] == '0')
                    {
                        expression[i] = ' ';
                        expression[i + 1] = '1';
                        expression[i + 2] = ' ';
                    }
                    if (expression[i] == '0' && expression[i + 2] == '1')
                    {
                        expression[i] = ' ';
                        expression[i + 1] = '1';
                        expression[i + 2] = ' ';
                    }
                    if (expression[i] == '1' && expression[i + 2] == '1')
                    {
                        expression[i] = ' ';
                        expression[i + 1] = '0';
                        expression[i + 2] = ' ';
                    }
                }
            }
        }

        if (expression[i] == '~')
        {
            if (expression[i + 1] == '1')
            {
                expression[i] = ' ';
                expression[i + 1] = '0';
            }
            else if (expression[i + 1] == '0')
            {
                expression[i] = ' ';
                expression[i + 1] = '1';
            }
        }
    }
}

char *Remove_Space(char *expression, int matrix_size)
{
    int i = 0, j = 0;
    char *strAUX = malloc(matrix_size * sizeof(char));

    for (i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] != ' ')
        {
            strAUX[j] = expression[i];
            j++;
        }
    }
    strAUX[j] = '\0';
    return strAUX;
}

void Remove_Parentheses(char *expression)
{
    int i = 0;

    for (i = 0; expression[i] != '\0'; i++)
    {
        if (expression[i] == '(')
        {
            if (expression[i + 2] == ')')
            {
                expression[i] = ' ';
                expression[i + 2] = ' ';
            }
        }
    }
}

void Organize_Expression(char *expression, int matrix_size, int n, char **propositions_truth_table)
{
    int i, j;
    for (i = 0; i < matrix_size; i++)
    {
        if (expression[i] >= 65 && expression[i] <= 90)
        {
            for (j = 0; j <= 25; j++)
                if (expression[i] == j + 65)
                    expression[i] = propositions_truth_table[j][n];
        }
    }
}

int main()
{
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");
    char expression[255], original_expression[255];
    int matrix_size, columns, i, j, k, n, s = 0;
    int num_of_characters, number_of_lines, counter_1 = 0, counter_0 = 0;
    char *new_expression, *output, *propositions;
    char **propositions_truth_table;

    while (!feof(input_file))
    {
        num_of_characters = 0, number_of_lines = 0, counter_1 = 0, counter_0 = 0;
        matrix_size = 0, columns = 0, i = 0, j = 0, k = 0, n = 0, s = 0;

        fgets(expression, 255, input_file);

        matrix_size = strlen(expression);

        for (i = 0; i <= matrix_size; i++)
        {
            if (expression[i] == '\n')
                expression[i] = '\0';
        }

        num_of_characters = Characters_Counter(matrix_size, &expression);

        propositions = Unidimensional_Matrix_Malloc(num_of_characters);
        Proposition_Array(expression, propositions);

        number_of_lines = pow(2, num_of_characters);

        columns = number_of_lines;

        for (i = 0; expression[i] != '\0'; i++)
            original_expression[i] = expression[i];

        original_expression[i] = '\0';

        propositions_truth_table = Bidimensional_Matrix_Calloc(num_of_characters, number_of_lines);

        for (i = 0; columns % 2 == 0; i++) // Fill the truth table with 0 or 1
        {
            columns = columns / 2;
            counter_1 = 0;
            counter_0 = 0;
            for (j = 0, k = 0; j < number_of_lines; j++)
            {

                if (k < columns)
                {
                    propositions_truth_table[i][j] = '1';
                    counter_1++;
                }
                else
                {
                    propositions_truth_table[i][j] = '0';
                    counter_0++;
                    if (counter_0 == counter_1)
                    {
                        k = 0;
                        continue;
                    }
                }
                k++;
            }
        }

        output = Unidimensional_Matrix_Malloc(number_of_lines);

        for (n = 0; n < number_of_lines; n++)
        {

            for (i = 0; expression[i] != '\0'; i++)
                expression[i] = original_expression[i];

            expression[i] = '\0';

            matrix_size = strlen(expression);

            Organize_Expression(expression, matrix_size, n, propositions_truth_table);

            new_expression = Matrix_Organizer(matrix_size, expression);

            while (matrix_size >= 2)
            {
                Operation_Not(new_expression);
                new_expression = Remove_Space(new_expression, matrix_size);

                Remove_Parentheses(new_expression);

                new_expression = Remove_Space(new_expression, matrix_size);

                Operations_1(new_expression);
                new_expression = Remove_Space(new_expression, matrix_size);

                Remove_Parentheses(new_expression);

                new_expression = Remove_Space(new_expression, matrix_size);

                Operations_2(new_expression, matrix_size);
                new_expression = Remove_Space(new_expression, matrix_size);

                Remove_Parentheses(new_expression);

                new_expression = Remove_Space(new_expression, matrix_size);

                matrix_size = strlen(new_expression);
            }

            output[s] = new_expression[0];
            s++;
        }
        output[s] = '\0';

        fprintf(output_file, "-----------------------------------------------------------------------------------------------\n");
        fprintf(output_file, "Expression: %s\n", original_expression);
        fprintf(output_file, "Solution: \n\n");

        for (j = 0; propositions[j] != '\0'; j++)
        {
            fprintf(output_file, "%c | ", propositions[j]);
        }
        fprintf(output_file, "S\n");

        for (j = 0; j < number_of_lines; j++)
        {
            for (i = 0; i < num_of_characters; i++)
            {
                fprintf(output_file, "%c | ", propositions_truth_table[i][j]);
            }
            fprintf(output_file, "%c", output[j]);
            fprintf(output_file, "\n");
        }
        fprintf(output_file, "-----------------------------------------------------------------------------------------------\n");
    }
    fclose(input_file);
    fclose(output_file);

    return 0;
}
