#pragma once

#include "DoubleList.tpp"

template <typename T>
DoubleList<T>::DoubleList(T *a, unsigned n) {
   
   if( n == 0 ){
      mHead[Blue] = mHead[Red] = nullptr;
      return ;
    }
    mHead[Blue] = new Node;
    mHead[Red] = mHead[Blue];
    mHead[Blue]->mValue = a[0];
    Node* cur;
    cur =  mHead[Blue];
    for( int  i = 1; i <= n-1 ; i++){
         cur->mNext[Blue] = cur->mNext[Red] = new Node;
         cur = cur -> mNext[Blue] ;
         cur->mValue = a[i];
    }

cur=nullptr;
}
template <typename T>
DoubleList<T>::DoubleList(const DoubleList<T> &dl) {
   Node* cur;
    cur = mHead[Blue];
    while( cur != nullptr){
       Node* temp = cur -> mNext[Blue];
       delete cur;
       cur = temp;
    }
  Node *temp = dl.mHead[Blue], *temp2;
  if( temp == nullptr ) 
      return ;
  Node *cloneHead, *curRed;
  cloneHead = new Node;
  cloneHead->mValue = temp->mValue;
  mHead[Blue] = cloneHead;
  cur = cloneHead;
  temp = temp->mNext[Blue];
  while( temp != nullptr){
     cur ->mNext[Blue] = new Node;
     cur = cur -> mNext[Blue];
     cur->mValue = temp->mValue;
     temp = temp -> mNext[Blue];
  }
  cur->mNext[Blue] = nullptr;
  temp2 = dl.mHead[Blue];
  temp = dl.mHead[Red];
  cur = mHead[Blue];
  while( temp != temp2 ){
    temp2 = temp2->mNext[Blue];
    cur= cur->mNext[Blue];
  }
  mHead[Red] = cur;
  curRed = cur;
  temp = dl.mHead[Red]-> mNext[Red];
  while( temp != nullptr ) {
      temp2 = dl.mHead[Blue];
      cur = mHead[Blue];
      while( temp != temp2 ){
         temp2 = temp2->mNext[Blue];
         cur= cur->mNext[Blue];
      }
      curRed-> mNext[Red] = cur;
      curRed = cur;
      temp = temp-> mNext[Red];
  }
  curRed -> mNext[Red ] = nullptr;
  curRed=nullptr;
cloneHead=nullptr;
temp=nullptr;
temp2=nullptr;
}

template <typename T>
typename DoubleList<T>::Node *DoubleList<T>::get(unsigned index,
                                                 Color color) const {
  Node* cur = mHead[color];
  if( cur == nullptr ){
      // thwrow exception
      throw InvalidIndexException();
      return nullptr;
  }
  for( int i = 0; i < index; i++){
       if( cur->mNext[color] == nullptr ){
           // throw exception
           throw InvalidIndexException ();
           return nullptr;
       }
       cur = cur -> mNext[color];
  }
   return cur;
}

template <typename T>
typename DoubleList<T>::Node *DoubleList<T>::insert(T value, unsigned redIndex,
                                                    unsigned blueIndex) {
  Node *curBlue, *prevBlue = nullptr, *nextBlue = nullptr;
  curBlue = mHead[Blue];
  if( curBlue == nullptr && blueIndex > 0 ){
       throw InvalidIndexException();
  }
  for( int i = 0; i < blueIndex; i++){
       prevBlue = curBlue;
       curBlue = curBlue->mNext[Blue];
       if( curBlue == nullptr ){
           if( i  < blueIndex - 1 ){
               // thwrow exception
               throw InvalidIndexException();
           }
       }
  }
  Node *curRed, *prevRed = nullptr, *nextRed = nullptr;
  curRed = mHead[Red];
  for( int i = 0; i < redIndex; i++){
       prevRed = curRed;
       curRed = curRed->mNext[Red];
       if( curRed == nullptr ){
           if( i  < redIndex - 1 ){
               // thwrow exception
               throw InvalidIndexException();
           }
       }
  }
  Node* addedNode = new Node;
  addedNode->mValue = value;
  if( prevBlue == nullptr ){
      addedNode->mNext[Blue] = mHead[Blue];
      mHead[Blue] = addedNode;
  }
  else {
      prevBlue->mNext[Blue] = addedNode;
      addedNode->mNext[Blue] = curBlue;
  }
  if( prevRed == nullptr ){
      addedNode->mNext[Red] = mHead[Red];
      mHead[Red] = addedNode;
  }
  else {
      prevRed->mNext[Red] = addedNode;
      addedNode->mNext[Red] = curRed;
  }
prevBlue=nullptr;
prevRed=nullptr;
curRed=nullptr;
curBlue=nullptr;
nextRed=nullptr;
nextBlue=nullptr;
  return addedNode;
addedNode=nullptr;

}

template <typename T>
void DoubleList<T>::remove(unsigned index, Color color) {
  Node *cur;
  cur = mHead[color];
  for( int i = 0; i < index && cur != nullptr ; i++){
       cur = cur -> mNext[color];
  }
  if( cur == nullptr)
      throw InvalidIndexException();
  Node *curBlue, *prevBlue = nullptr, *nextBlue = nullptr;
  curBlue = mHead[Blue];
  nextBlue = curBlue -> mNext[Blue];
  for( int i = 0; curBlue != cur ; i++){
       prevBlue = curBlue;
       curBlue = curBlue->mNext[Blue];
       nextBlue = curBlue -> mNext[Blue];
  }
  Node *curRed, *prevRed = nullptr, *nextRed = nullptr;
  curRed = mHead[Red];
  nextRed = curRed -> mNext[Red];
  for( int i = 0; curRed != cur; i++){
       prevRed = curRed;
       curRed = curRed->mNext[Red];
       nextRed = curRed -> mNext[Red];
  }
  if( prevBlue == nullptr )
      mHead[Blue] = nextBlue;
  else
      prevBlue-> mNext[Blue] = nextBlue;
  if( prevRed == nullptr )
      mHead[Red] = nextRed;
  else
      prevRed-> mNext[Red] = nextRed;
  delete cur;
    cur=nullptr;
curRed=nullptr;
curBlue=nullptr;
prevBlue=nullptr;
prevRed=nullptr;
nextBlue=nullptr;
nextRed=nullptr;

}

template <typename T>
void DoubleList<T>::append(DoubleList<T> &dl) {
     Node *temp = dl.mHead[Blue], *temp2;
  Node *lastBlue = mHead[Blue], *lastRed = mHead[Red];
  if( lastBlue != nullptr){
  while( lastBlue->mNext[Blue] != nullptr) {
         lastBlue = lastBlue->mNext[Blue];
         lastRed = lastRed->mNext[Red];
  }}
  Node *cloneHead, *cur, *curRed;
  cloneHead = new Node;
  cloneHead->mValue = temp->mValue;
  if( lastBlue == nullptr )
      mHead[Blue] = cloneHead;
  else 
  lastBlue->mNext[Blue] = cloneHead;
  cur = cloneHead;
  temp = temp->mNext[Blue];
  while( temp != nullptr){
     cur ->mNext[Blue] = new Node;
     cur = cur -> mNext[Blue];
     cur->mValue = temp->mValue;
     temp = temp -> mNext[Blue];
  }
  cur->mNext[Blue] = nullptr;
  temp2 = dl.mHead[Blue];
  temp = dl.mHead[Red];
  cur = cloneHead;
  while( temp != temp2 ){
    temp2 = temp2->mNext[Blue];
    cur= cur->mNext[Blue];
  }
  if( lastRed == nullptr) 
      mHead[Red] = cur;
  else 
  lastRed->mNext[Red] = cur;
  curRed = cur;
  temp = dl.mHead[Red] -> mNext[Red];
  while( temp != nullptr ) {
      temp2 = dl.mHead[Blue];
      cur = cloneHead;
      while( temp != temp2 ){
         temp2 = temp2->mNext[Blue];
         cur= cur->mNext[Blue];
      }
      curRed-> mNext[Red] = cur;
      curRed = cur;
      temp = temp-> mNext[Red];
  }
  curRed -> mNext[Red ] = nullptr;
 
    cur = dl.mHead[Blue];
    //cur = mHead[Blue];
    while( cur != nullptr){
       Node* temp = cur -> mNext[Blue];
       delete cur;
       cur = temp;
    }
    dl.mHead[Blue] = dl.mHead[Red] = nullptr;
   temp=nullptr;
cloneHead=nullptr;
lastBlue=nullptr;
lastRed=nullptr;
temp2=nullptr;
curRed=nullptr;


}

template <typename T>
DoubleList<T>::~DoubleList() {
    Node* cur;
    cur = mHead[Blue];
    while( cur != nullptr){
       Node* temp = cur -> mNext[Blue];
       delete cur;
       cur = temp;
        temp=nullptr;

    }
cur=nullptr;
}