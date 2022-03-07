#define max 5
int q[max];
int f=-1,r=-1;
void dequeue()
{
if(f==-1 && r==-1)
printf("Circular queue is underflow.\n");
else
printf("Deleted element = %d\n",q[f]);
if(r==f)
{
r=-1;
f=-1;
}
else if(f==max-1)
f=0;
else
f+=1;
}
void size()
{
if (f==-1 && r==-1)
printf("Circular queue size : 0\n");
else if (f<=r)
printf("Circular queue size : %d\n",(r-f)+1);
else
printf("Circular queue size : %d\n",max-f+r+1);
}
void isEmpty()
{
if(f==-1 && r==-1)
printf("Circular queue is empty.\n");
else
printf("Circular queue is not empty.\n");
}
void enqueue(int x)
{
if(((r==max-1)&&(f==0))||(f==r+1))
printf("Circular queue is overflow.\n");
else
{
if(r==max-1)
r=-1;
else if(f==-1)
f=0;
r++;
q[r]=x;
printf("Successfully inserted.\n");
}
}
void display()
{
int i;
if(f==-1 && r==-1)
printf("Circular queue is empty.\n");
else
{
printf("Elements in the circular queue : ");
if(f<=r)
{
for(i=f;i<=r;i++)
printf("%d ",q[i]);
}
else
{
for(i=f;i<=max-1;i++)
printf("%d ",q[i]);
for(i=0;i<=r;i++)
printf("%d ",q[i]);
}
printf("\n");
}
}