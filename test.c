#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:4996)//取消scanf返回值的警告

//100桶饮料 1桶有毒
//志愿者中毒2小时有反应  持续20分钟
// 三小时要找出有毒的那桶
// 最少需要多少志愿者
//2的7次方128》100  7个志愿者就够了
#include <stdio.h>
#include <math.h>

int main()
{
	//int n = pow(2, 3);
	int a[7] = { 0 };
	for (int i=1;i<=100;i++)//遍历100个人
	{
		for (int j=1;j<=100;j*=2)//用二进制表示7个杯子 每个杯子代表着7位二进制哪个是1 有的就放对应的a数组的7个杯子里
		{
			if ((i&j)==j)
			{
				for (int n=0;n<7;n++)
				{
					if (pow(2,n)==j)
					{
						a[n]++;
					}
				}
			}
		}
	}
	//看a数组下标1-7中7个志愿者 谁喝了有反应
	int poisoningnum;//有毒毒桶的号码=中毒的所有中毒志愿者 2的下标次方   的总和

	//比如 是0 4 6号杯子的人中毒 
	poisoningnum = pow(2, 0) + pow(2, 4) +pow(2,6);
	printf("有毒的桶是：%d\n", poisoningnum);
	return 0;
}