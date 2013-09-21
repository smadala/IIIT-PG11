while(first<last){
temp=*(orginal+first);
*(orginal+first)=*(orginal+last);
*(orginal+last)=temp;
++first;
--last;
}
