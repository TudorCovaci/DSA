#pragma once
typedef int TElem;
typedef TElem TComp;
class Node {
private:
	TComp info_;
	int leftChild_;
	int rightChild_;
	int parent_;
public:
	void setInfo(TElem info) { info_ = info; }
	void setLeftChild(int leftChildIndex) { leftChild_ = leftChildIndex; }
	void setRightChild(int rightChildIndex) { rightChild_ = rightChildIndex; }
	void setParent(int parentIndex) { parent_ = parentIndex; }
	TComp getInfo() { return info_; }
	int getLeftChild() { return leftChild_; }
	int getRightChild() { return rightChild_; }
	int getParent() { return parent_; }

};