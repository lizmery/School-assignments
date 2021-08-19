//
//  bmi.c
//  BMI
//
//  Created by Liz Vigil on 9/25/20.
//  Copyright © 2020 Liz Vigil. All rights reserved.
//

#include <stdio.h>

void calculateBMI(void);

FILE * fp;

int main()
{
    int i;
    
    fp = fopen("csis.txt", "w");
    
    for (i = 1; i <= 4; ++i)
    {
        calculateBMI();
    }
    
    fclose(fp);
    return 0;
}

void calculateBMI(void)
{
    double weight, height;
    double bmi;
    
    printf("Enter your weight (pounds) and height (inches): ");
    fprintf(fp, "Enter your weight (pounds) and height (inches): ");
    scanf("%lf %lf", &weight, &height);
    
    bmi = (weight * 703) / (height * height);
    
    if (bmi < 18.5)
    {
        printf("BMI = %4.1lf, underweight.\n", bmi);
        fprintf(fp, "BMI = %4.1lf, underweight.\n", bmi);
    }
    if (bmi >= 18.25 && bmi < 25.0)
    {
        printf("BMI = %4.1lf, normal.\n", bmi);
        fprintf(fp, "BMI = %4.1lf, normal.\n", bmi);
    }
    if (bmi >= 25.0 && bmi < 30.0)
    {
        printf("BMI = %4.1lf, overweight.\n", bmi);
        fprintf(fp, "BMI = %4.1lf, overweight.\n", bmi);
    }
    if (bmi >= 30.0)
    {
        printf("BMI = %4.1lf, obese.\n", bmi);
        fprintf(fp, "BMI = %4.1lf, obese.\n", bmi);
    }
    
    printf("\n");
    fprintf(fp, "\n");
    
    return;
}
