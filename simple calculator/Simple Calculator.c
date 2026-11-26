#include <stdio.h>

int main(void) {
    char op;
    double a, b;
    char again;

    do {
        printf("\n=== Simple Calculator ===\n");
        printf("Operators: +  -  *  /  %%\n");
        printf("Enter expression (e.g. 12 + 5): ");

        if (scanf("%lf %c %lf", &a, &op, &b) != 3) {
            printf("Invalid input. Please try again.\n");
            while (getchar() != '\n');   /* clear input buffer */
            continue;
        }

        switch (op) {
            case '+':
                printf("Result: %.2f + %.2f = %.2f\n", a, b, a + b);
                break;
            case '-':
                printf("Result: %.2f - %.2f = %.2f\n", a, b, a - b);
                break;
            case '*':
                printf("Result: %.2f * %.2f = %.2f\n", a, b, a * b);
                break;
            case '/':
                if (b == 0)
                    printf("Error: Division by zero is not allowed.\n");
                else
                    printf("Result: %.2f / %.2f = %.2f\n", a, b, a / b);
                break;
            case '%':
                /* Modulus works on integers in C */
                if ((int)b == 0)
                    printf("Error: Modulus by zero is not allowed.\n");
                else
                    printf("Result: %d %% %d = %d\n", (int)a, (int)b, (int)a % (int)b);
                break;
            default:
                printf("Error: Unknown operator '%c'.\n", op);
        }

        printf("\nCalculate again? (y/n): ");
        scanf(" %c", &again);
    } while (again == 'y' || again == 'Y');

    printf("Goodbye!\n");
    return 0;
}