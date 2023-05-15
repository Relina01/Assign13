#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 20

typedef int element;

typedef struct
{
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} DequeType;

void init_deque(DequeType* q)
{
	q->front = q->rear = 0;
}

int is_empty(DequeType* q)
{
	return (q->front == q->rear);
}

int is_full(DequeType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void add_rear(DequeType* q, element item)
{
	if (is_full(q))
	{
		return;
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element delete_front(DequeType* q)
{
	if (is_empty(q))
	{
		return;
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

element get_front(DequeType* q)
{
	if (is_empty(q))
	{
		return;
	}
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

void add_front(DequeType* q, element val)
{
	if (is_full(q))
	{
		return;
	}
	q->data[q->front] = val;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

element delete_rear(DequeType* q)
{
	int perv = q->rear;
	if (is_empty(q))
	{
		return;
	}
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[perv];
}

element get_rear(DequeType* q)
{
	if (is_empty(q))
	{
		return;
	}
	return q->data[q->rear];
}

int check_palin(char* s[])
{
	int i = 0, j = 0;
	DequeType deque;
	init_deque(&deque);

	while (s[i] != NULL)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			add_rear(&deque, s[i]);
		}
		else if (s[i] >= 'A' && s[i] <= 'Z')
		{
			char ch = s[i] + ('a' - 'A');
			add_rear(&deque, ch);
		}
		i++;
	}
	i = 0;
	while (deque.front != deque.rear)
	{
		if (get_rear(&deque) != delete_front(&deque))
			return 0;
		delete_rear(&deque);
	}
	return 1;
}

int main()
{
	char* s[100] = { NULL };
	int check;
	char answer;

	while (1)
	{
		printf("Enter String : ");
		gets_s(s, sizeof(s));
		check = check_palin(&s);
		if (check == 1) printf("It's Palindrome\n");
		else printf("It's not Palindrome\n");

		printf("More try?(y or n) : ");
		scanf_s("%c", &answer);
		if (answer == 'Y' || answer == 'y')
		{
			check = 0;
			for (int i = 0; i < 100; i++)
				s[i] = NULL;
			continue;
		}
		else if (answer == 'N' || answer == 'n')
		{
			printf("Exit\n");
			break;
		}
	}
	return 0;
}