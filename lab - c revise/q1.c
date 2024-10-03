// Write a program to find the average expenditure of a company for each month of each year, each year and average over the range of years specified. Use arrays to construct a table, display the table of expenditure and find the sum and average.

#include <stdio.h>

int main() {
    int start, end;
    printf("Enter starting and ending year: ");
    scanf("%d %d", &start, &end);
    int total_year = end - start + 1;
    int arr[total_year][12];

    for (int i = 0; i < total_year; i++) {
        for (int j = 0; j < 12; j++) {
            printf("Enter expenditure of %d year %d month: ", start + i, j + 1);
            scanf("%d", &arr[i][j]);
        }
    }

    // sum and avg year wise
    int year_sum[total_year];
    int year_avg[total_year];
    for (int i = 0; i < total_year; i++) {
        year_sum[i] = 0;
        for (int j = 0; j < 12; j++) {
            year_sum[i] += arr[i][j];
        }
        year_avg[i] = year_sum[i] / 12;
    }

    // sum and avg month wise
    int month_sum[12] = {0};
    int month_avg[12];
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < total_year; j++) {
            month_sum[i] += arr[j][i];
        }
        month_avg[i] = month_sum[i] / total_year;
    }

    // sum and avg of all years
    int all_sum = 0, all_avg = 0;
    for (int i = 0; i < total_year; i++) {
        all_sum += year_sum[i];
    }
    all_avg = all_sum / (total_year * 12);

    // output
    printf("Year \t Jan \t Feb \t Mar \t Apr \t May \t Jun \t Jul \t Aug \t Sep \t Oct \t Nov \t Dec \t Sum \t Average\n");
    for (int i = 0; i < total_year; i++) {
        printf("%d\t", start + i);
        for (int j = 0; j < 12; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("%d\t%d\n", year_sum[i], year_avg[i]);
    }

    printf("Sum:\t");
    for (int i = 0; i < 12; i++) {
        printf("%d\t", month_sum[i]);
    }
    printf("\nAverage:");
    for (int i = 0; i < 12; i++) {
        printf("%d\t", month_avg[i]);
    }
    printf("\nOverall Sum: %d\n", all_sum);
    printf("Overall Average: %d\n", all_avg);

    return 0;
}
