#!/bin/bash

# Prompt the user to enter the numbers
echo "Enter the numbers separated by spaces:"
read -a numbers

# Initialize max with the first element of the array
max=${numbers[0]}

# Loop through the array to find the greatest number
for num in "${numbers[@]}"
do
    if ((num > max)); then
        max=$num
    fi
done

echo "The greatest number in the array is: $max"
