let node =(value,next=null)=>({value,next})

let list=(arr)=>arr.length===0?null:node(arr[0],list(arr.slice(1)));

//NOTE(rsvn):not considered edge cases like index out of bound
let getNode=(index,list)=>{
  if(index==0)return({value:list.value,next:list.next})
  return getNode(index-1,list.next)}

let linkedList=list([1,2,4,5,6,7])


let print=(list)=>{
  if(list==null) return
  console.log(list.value)
return print(list.next)}

let head=(list)=>({value:list.value,next:list.next});

//NOTE(rsvn):here we are not changing original list instead making a new copy 
let setNode=(index,list,val)=>{
 if(index==0)return node(val,list)
  return node(list.value,setNode(index-1,list.next,val))
}

let removeNode=(index,list)=>{
 if(index==1)return node(list.next.value,list.next)
  return node(list.value,setNode(index-1,list.next))
}



let ll=setNode(2,linkedList,3)
let newList=removeNode(5,ll)

print(newList)
