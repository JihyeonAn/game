#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
	char word[30];
	int length;
	bool isPalindrome= true;
	
	printf("단어를 입력하세요: ");
	scanf("%s",word);
	
	length=strlen(word);
	
	for(int i=0;i<length/2;i++)
	{
		if(word[i] != word[length-1-i])
		{
			isPalindrome = false;
			break;
		}
	}
	if(isPalindrome=1){
		printf("true");
	}
	else printf("false");
	
	
	return 0;
}

