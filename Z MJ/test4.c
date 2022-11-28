#include<stdio.h>
#include<stdlib.h>  
#include<string.h>
#include<math.h>
#include<signal.h>
#define rep(i,a,b) for(int i=a; i<b ;i++)
//页表项  
struct Page{
	int pNo,bNo;
	int P,A;
	struct Page * Page1;
	struct Page * Page2;
};
struct Page Page1(){};
struct Page Page2(struct Page page3,int _pNo,int _bNo,int _P,int _A){
		page3.pNo=_pNo;
		page3.bNo=_bNo;
		page3.P=_P;
		page3.A=_A;
	}

//页节点 
struct PQNode{
	struct Page * page;
	struct PQNode *pre,*next;
};
//PCB为进程控制块 
struct PCB{
	struct Page *head;
	int pCount;
};
int pSize,bCount,size;
struct PQNode *pqHead,*pqTail;
int *bmp;
//将页节点插入到队列头部 
void InsertNode(struct PQNode *pqNode){
	pqNode->page->P = 1;
	pqNode->page->A = 1;
	pqNode->pre = NULL;
	pqNode->next = pqHead;
	pqHead->pre = pqNode;
	pqHead = pqNode;
}
//将一个页队列节点移除 
void RemoveNode(struct PQNode *pqNode){
	pqNode->pre->next = pqNode->next;
	pqNode->next->pre = pqNode->pre;
}
//初始化页大小，块数大小，页表队列 
void SysInit(){
	printf("请求输入页大小："); 
	scanf("%d",&pSize);
	printf("请求输入总块数：");
	scanf("%d",&bCount);
	bmp = (int *)malloc(sizeof(int)*bCount);
	for(int i = 0;i < bCount; i++){
		bmp[i]=0;
	} 
	pqHead = (struct PQNode*)malloc(sizeof(struct PQNode));
	pqTail = pqHead;
}
//缺页中断处理 
void LackPage(struct Page *page){
	struct PQNode * newNode = (struct PQNode*)malloc(sizeof(struct PQNode));
	newNode->page = page;
	newNode->next= NULL;
	newNode->pre = NULL;
	int pos=0;
	for(;pos<bCount&&bmp[pos];pos++);
	if(pos == bCount){
		InsertNode(newNode);
		page->bNo = pos-1;
		pqTail->pre->page->P = 0;
		pqTail->pre->pre->next = NULL;
		pqTail = pqTail->pre->pre;
	}
	else{
		bmp[pos] = 1;
		InsertNode(newNode);
		page->bNo = pos;
	}
}
//未发生缺页中断时处理 
void NonLackPage(struct Page * page){
	struct PQNode *tmp = pqHead;
	while(tmp&&tmp->page->bNo != page->bNo){
		tmp = tmp->next;
	}
	if(tmp != pqHead){
		RemoveNode(tmp);
		InsertNode(tmp);
	} 
}
//重定位 
int Relocate(struct PCB *p, int logAddr){
	int phyAddr,pnum,w;
	pnum = logAddr/pSize;
	w = logAddr % pSize;
	/*if(pnum > p->pCount-1 || pnum < 0){
		return -1;
	}*/
	if(p->head[pnum].P == 0){
		printf("缺页\n");
		LackPage(&p->head[pnum]);
	}
	else{
		p->head[pnum].A = 1;
		NonLackPage(&p->head[pnum]);
	}
	phyAddr = (p->head[pnum]).bNo*pSize + w;
	return phyAddr;
}
//初始化页表，PCB 
struct PCB *NewProc(){
	printf("请输入进程大小：");
	scanf("%d",&size);
	struct Page page4;
	struct Page *plist;
	struct PCB *pcb = (struct PCB*)malloc(sizeof(struct PCB));
	int cnt = (size-1)/pSize+1;
	plist = (struct Page*)malloc(sizeof(struct Page)*cnt);
	rep(i,0,cnt) {
		plist[i] = Page2(page4,i,-1,0,0);
	}
	pcb->head = plist;
	pcb->pCount = (size + pSize - 1)/pSize;
	return pcb;
}
//重定位得到物理地址 
void Access(struct PCB *p){
	printf("请输入欲访问的逻辑地址");
	int logAddr,phyAddr;
	scanf("%d",&logAddr);
	phyAddr = Relocate(p,logAddr);
	if(phyAddr<0){
		printf("访问被拒绝\n");
		printf("%d",phyAddr);
	} 
	else{
		printf("phyAddr: %d\n",phyAddr);
	}
}
int main(){
	SysInit();
	struct PCB *p = NewProc();
	while(1){
		Access(p);
	}
	return 0;
}

/****************************************
	*先进先出转换算法 
****************************************/ 
/*
先进先出转换算法
public class FIFO {	
	 内存块的个数
	public static final int N = 3;	
	  内存块数组
	Object[] array = new Object[N];
	private int size;

 	内存是非空为否
	public boolean isEmpty() {
		if(0 == size)
			return true;
		else
			return false;
	}
	
	
	内存是非空满

	 public boolean isFulled() {
		if(size >= N) 
			return true;
		else 
			return false;
	}
	
	元素(页框)的个数

	public int size() {
		return size;
	}

	 查找元素o在数组中的位置

	public int indexOfElement(Object o) {
		for(int i=0; i<N; i++) { 
			if(o == array[i]) {
				return i;
			}
		}
		return -1;
	}	
	//public void push(Object o) {
	//	Node p = new Node(o);
		//Node p2 = head;
	//	p.next = head;	
	//	head = p;
//	}

	  页面转换

	public Object trans(Object obj){
		Object e = null;
		int t = 0;
		if(indexOfElement(obj) != -1) {
			t = indexOfElement(obj);
			for(int i=t; i<size-1; i++) {
				array[i] = array[i+1];
			}
			array[size-1] = obj;
		} else {
			if(!isFulled()){
				array[size] = obj;
				size ++;
			} else {
				for(int i=0; i<size-1; i++) {
					array[i] = array[i+1];
				}
				array[size-1] = obj;
			}
		}
		if( -1 == t) {
			return null;
		} else {
			return array[t];
		}
	}

	输出内存区中的各数据
	 
	public void showMemoryBlock() {
		for(int i=0; i<size; i++) {
			System.out.print(array[i] + "        ");
		}
	}
	
	 清空队列(页框)
	
	public void clear(){
		
	}
	public static void main(String[] args) {
		Integer iter[] = {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
		FIFO fifo = new FIFO();
		for(int i=0; i<iter.length; i++) {
			fifo.trans(iter[i]);
			fifo.showMemoryBlock();
			System.out.println();
		}
	}

}
*/
/***************************************************
		时钟置换算法
****************************************************/ 
/* 
int nru[N];//表示 物理块 i 最近时候被访问过 
int page_in_block[N];//页面 i 在 block的下标索引 
int clock(){
    int index = 1;
    int page_lack = 0;
    memset(block, -1, sizeof(block));
    for(int i=1; i<=n; ++i){
        if(page_in_block[page[i]]){//如果page[i]已经在内存中 
            nru[page_in_block[page[i]]] = 1;//重新标记这个物理块中的页面被访问过了 
            cout<<endl<<"第"<<i<<"次: 页面"<<page[i]<<"已经存在物理块"<< page_in_block[page[i]] << "中!"<<endl;
        }
        else {
            while(true){
                if(index > m) index = 1;
                if(block[index] == -1) {
                    nru[index] = 1;
                    page_in_block[page[i]] = index;
                    block[index++] = page[i];
                    ++page_lack;
                    break;
                }
                if(block[index] == page[i]){
                    nru[index++] = 1;
                    break;
                } else {
                    if(nru[index] == 0){//替换该页面 
                        nru[index] = 1;
                        page_in_block[block[index]] = 0;
                        cout<<endl<<"第"<<i<<"次: 物理块"<<index<<"中的页面"<< block[index] <<"最近未被使用，将要被页面"<<page[i]<<"替换!"<<endl;
                        page_in_block[page[i]] = index;
                        block[index++] = page[i];
                        ++page_lack;
                        break;
                    } else
                        nru[index++] = 0;
                }
            } 
        }
        for(int k=1; k<=m; ++k)    
            cout<<block[k]<<" ";
        cout<<endl;
    }
    return page_lack;
}
*/ 
