//
//  main.c
//  广度优先BFS
//
//  Created by 罗展 on 2017/2/16.
//  Copyright © 2017年 cass. All rights reserved.
//

#include <stdio.h>

/*广度优先搜索*/
struct note
{
    int x;      //横坐标
    int y;      //纵坐标
    int f;       //队列路径编号
    int s;      //步数
};

int main(int argc, const char * argv[]) {
    
    struct note que[2501];   //记录整个地图的队列
    int a[51][51] = {0}, book[51][51] = {0};
    
    //定义一个表示方向的数组
    int next[4][2] = {{0,1},        //右
                            {1,0},         //下
                            {0,-1},       //左
                            {-1,0}};      //上
    
    int head, tail;
    int i, j, k, n, m, startx, starty, p, q, tx, ty, flag;
    
    //地图大小
    scanf("%d    %d", &n, &m);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    
    //输入起始点和目的地
    scanf("%d %d %d %d", &startx, &starty, &p, &q);
    
    //初始化队列
    head = 1;
    tail = 1;
    
    //往队列插入迷宫入口坐标
    que[tail].x = startx;
    que[tail].y = starty;
    que[tail].f = 0;
    que[tail].s = 0;
    tail++;
    //标记起始点为已走过
    book[startx][starty] = 1;
    //用来标记是否达到目的地，0表示未到达，1表示到达
    flag = 0;
    
    //当队列不为空时循环
    while (head < tail) {
        //枚举4个方向
        for (k = 0; k <= 3; k++) {
            tx = que[head].x + next[k][0];
            ty = que[head].y + next[k][1];
            
            //判断是否越界
            if (tx < 1 || tx > n || ty < 1 || ty > m)
                continue;
            
            //判断是否是障碍或者已在路径中
            if (a[tx][ty] == 0 && book[tx][ty] == 0) {
                //把这个点标记为已走过
                book[tx][ty] = 1;
                
                //插入新的点到队列
                que[tail].x = tx;
                que[tail].y = ty;
                que[tail].f = head;
                que[tail].s = que[head].s + 1;
                tail++;
            }
            
            //如果到了目标点停止扩展，结束任务
            if (tx == p && ty == q) {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            break;
        head++;
    }
    
    //打印队列中末尾最后一个点的步数
    printf("%d", que[tail - 1].s);
    
    return 0;
}
