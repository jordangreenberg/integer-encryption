#include <stdio.h>
#include <math.h>

//The following functions encrypt an integer of at least 6 digits

//Reads in input of integer at least 6 digits repeatedly until valid input provided
void input(int *num) {
    
    //Get input from user
    do {
        printf("Please enter an integer greater than 99999: ");
        scanf("%d", num);
        
        //Output error message if necessary
        if (*num <= 99999) {
            printf("Incorrect input.\n");
            
        } 
        else {
            printf("The number entered is %d\n", *num);
        }
            
    } while(*num <= 99999);
    
}

//Determines number of digits in an integer
int findNumDigits(int num) {
    int tempNum = num;
    int numDigits = 0;
    
    do {
        tempNum = tempNum / 10;
        numDigits++;
    } while(tempNum > 0);
    return (numDigits);
}

//Adds 4 to each digit of the integer, each digit ranges between 0-9
int add4(int num) {
    
    //Determine number of digits in the number
    int numDigits = findNumDigits(num);
    
    //Create new encrypted number
    int encryptedNum = 0;
    for (int i = 0; i < numDigits; i++) {
        int digit = 0;
        
        //Add 4 to each digit, ensuring digit is between 0-9
        digit = (num % 10) + 4;
        
        if (digit > 9) {
            digit -= 10;
        }
        
        //Add encrypted digit to encrypted number
        encryptedNum += digit * pow(10, i);
        
        num =  num / 10;
    }
    
    
    return (encryptedNum);
}

//Shifts position of each digit to the left one decimal place
int shift(int num) {
    
    //Determine number of digits in the number
    int numDigits = findNumDigits(num);
    
    //Shift every digit left
    int firstDigit = num / (pow(10, numDigits - 1));
    num = num % (int) (pow(10, numDigits - 1));
    num = num * 10 + firstDigit;

    return num;
}

//Prints out original number and encrypted number
void printOutput(int encryptNum, int originalNum) {
    printf("Original number: %d\n", originalNum);
    printf("Encrypted number: %d\n", encryptNum);
}

/**int main(int argc, char **argv)
{
	//Declare variables
    int number = 0;
    
    //Get input from user
    input(&number);
    int original = number;
    
    number = add4(number);
    
    number = shift(number);
    
    printOutput(number, original);
    
	return 0;
}
*/
