# Add Two Binary Numbers

## My solution 1    2019/10/24  1 hour

FAIL

```
char * addBinary(char * a, char * b) {
    int a_size = strlen(a),     /* exclude '\0' !!! */
        b_size = strlen(b);
    int sum_size;
    if (a >= b) sum_size = a_size + 1;   /* assume that the last digit will be added by a positive carry */
    else sum_size = b_size + 1;

    char *sum = (char *) malloc (sizeof(char)*(sum_size+1));    /* thus we implement the variable length string */
    sum[sum_size] = '\0';
    sum[0] = '0';

    int i, current_sum,
        carry = 0;
    for (i = 0; i < sum_size; i++) {
        /* from 0 to sum_size-1 ??? */
        if ((a_size-1-i>=0)&&(b_size-1-i>=0)) {   /* check if one of the string is run out */
            current_sum = a[a_size-1-i] + b[b_size-1-i] + carry - 144;    /* minus the ASCII offset */
        } else {
            if ((a_size-1-i < 0) && (b_size-1-i >= 0)) {
                current_sum = b[b_size-1-i] + carry - 96;
            } else if ((a_size-1-i >= 0) && (b_size-1-i < 0)) {
                current_sum = a[a_size-1-i] + carry - 96;
            } else {
                break;
            }
        }
        if (current_sum == 0) {
            carry = 0;
            sum[i] = '0';
        } else if (current_sum == 1) {
            carry = 0;
            sum[i] = '1';
        } else if (current_sum == 2) {
            carry = 1; 
            sum[i] = '0';
        } else if (current_sum == 3) {
            carry = 1;
            sum[i] = '1';
        }
    }
    if (carry == 1) {
        sum[0] = '1';
        return sum;
    } else {
        char *littleSum = (char *) malloc (sizeof(char)*(sum_size));
        littleSum[sum_size-1] = '\0';
        for (i = 0; i < sum_size-2; i++) {
            littleSum[i] = sum[i+1];
        }
        free(sum);
        return littleSum;
    }
}
```