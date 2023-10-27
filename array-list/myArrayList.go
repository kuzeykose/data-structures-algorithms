package main

import "fmt"

func new() []int{
  var arr []int
  return arr
}

func append(arr *[]int, val int){
  myArr := *arr

  newArr := make([]int, len(myArr)+1)
  for i, v := range myArr{
    newArr[i] = v
  }

  newArr[len(newArr)-1] = val
  *arr = newArr
}

func remove(arr *[]int, rmIndex int){
  myArr := *arr
  newArr := make([]int, len(myArr)-1)

  i := 0
  for i < rmIndex {
    newArr[i] = myArr[i]
    i++
  }
  for i < len(newArr){
    newArr[i] = myArr[i+1]
    i++
  }

  *arr = newArr
}

func get(arr []int, index int) int {
  return arr[index]
}

func size(arr []int) int{
  return len(arr);
}

func main(){
  myArray := new()

  append(&myArray, 1)
  append(&myArray, 2)

  fmt.Println(myArray)

  remove(&myArray, 1)

  fmt.Println(myArray)
  fmt.Println(size(myArray))
  fmt.Println(len(myArray))
}
