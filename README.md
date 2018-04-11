# DS_HW3_List_of_Christmas_gifts

## Description

### Objective

- Implement a linked list to store Christmas gifts
- Each node stores a gift and its corresponding price
- Price is a integer and ranges from 0 to 999
- Each gift price is unique, two duplicate prices will not exist at the same time
 
>Examples  
>(hat, 150) -> (candy, 250) -> (book, 300)  ok  
>(hat, 150) -> (candy, 150) -> (book, 300)  incorrect


### Requirements

You should implement 4 functions below

- InsertBack(gift, price)
- InsertAfter(gift, price, priceToInsertAfter)
- Delete(price)
- Reverse()

**InsertBack(gift, price)**  
>Insert a (gift,price) to the end of the linked list

**InsertAfter(gift, price, priceToInsertAfter)**  
>Insert (gift,price) after priceToInsertAfter  
>If price does not exist in the linked list, **do nothing**

**Delete(price)**  
>Remove the (gift,price) matched price from the linked list  
>If this price does not exist in the linked list, **do nothing**

**Reverse()**  
>Reverse the linked list

## Input
The last line of input is `End`, and we only need to print the result when getting the `End`.  
*Sample Input:*  
```
InsertBack dog 15  
InsertBack paper 25  
InsertBack pen 45  
InsertBack book 350  
InsertAfter mug 250 45  
Delete 25  
Reverse  
InsertBack paper 50  
InsertAfter comb 350 25  
InsertAfter comb 270 45  
Reverse  
End  
```

## Output
Print:  
- First line: `Empty` or `List`  
- Second line: List of gifts and their corresponding prices  

Connect with symbols `->`.  
**No spaces** in between.  
If it's empty, only need to print the first line.

*Sample Output:*
```
List  
(paper,50)->(dog,15)->(comb,270)->(pen,45)->(mug,250)->(book,350)
```
