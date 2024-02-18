#include <stdio.h>
#include <conio.h>
#define MAX 10

int queue_[MAX];
int front_ = -1, rear_ = -1;

void InsertElement_() {
	int num;

	printf("\nQueue에 삽입할 숫자를 입력해: ");
	scanf_s("%d", &num);

	if ((front_ == 0 && rear_ == MAX - 1) || (rear_ + 1 == front_)) {
		printf("\nOVERFLOW");
		
		return;
	}
	else if (front_ == -1 && rear_ == -1) {
		front_ = rear_ = 0;
	}
	else if (front_ != 0 && rear_ == MAX-1) {
		rear_ = 0;
	}
	else {
		rear_++;
	}

	queue_[rear_] = num;
}

int DeleteElement_() {
	int val;

	if (front_ == -1 && rear_ == -1) {
		printf("\nUNDERFLOW");
		
		return -1;
	}

	val = queue_[front_];

	if (front_ == rear_) {
		front_ = rear_ = -1;
	}
	else if (front_ == MAX - 1) {
		front_ = 0;
	}
	else {
		front_++;
	}

	return val;
}

int Peek_() {
	if (front_ == -1 && rear_ == -1) {
		printf("Queue is empty!");

		return -1;
	}

	return queue_[front_];
}

void Display_() {
	int i;
	printf("\n");

	if (front_ == -1 && rear_ == -1) {
		printf("\nQueue is empty!");
	}
	else {
		if (front_ <= rear_) {
			for (i = front_; i <= rear_; i++) {
				printf("\t%d\n", queue_[i]);
			}
		}
		else {
			for (i = front_; i <= MAX-1; i++) {
				printf("\t%d\n", queue_[i]);
			}
			for (i = 0; i <= rear_; i++) {
				printf("\t%d\n", queue_[i]);
			}
		}
	}
}

int main() {
	int option, val;

	do {
		printf("\n*** MAIN MENU ***");
		printf("\n1. Insert");
		printf("\n2. Delete");
		printf("\n3. Peek");
		printf("\n4. Display");
		printf("\n5. EXIT");
		printf("\nEnter your option: ");
		scanf_s("%d", &option);

		switch (option) {
		case 1:
			InsertElement_();

			break;
		case 2:
			val = DeleteElement_();

			if (val != -1)
				printf("\n삭제되었던 숫자는: %d", val);

			break;

		case 3:
			val = Peek_();

			if (val != -1)
				printf("QUeue의 첫 번쨰 값은: %d", val);

			break;

		case 4:
			Display_();

			break;
		}
	} while (option != 5);

	_getch();

	return 0;
}