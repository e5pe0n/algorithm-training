package scala

class FixedMultiStack(val capacity: Int) {
  val numOfStack = 3
  val vals: Array[Int] = new Array(capacity * numOfStack)
  val sizes: Array[Int] = new Array(numOfStack)

  def push(stackNum: Int, x: Int): Unit = {
    if (isFull(stackNum)) throw new FullStackException
    sizes(stackNum) += 1
    vals(idxOfTop(stackNum)) = x
  }

  def pop(stackNum: Int): Int = {
    if (isEmpty(stackNum)) throw new EmptyStackException
    val topIdx = idxOfTop(stackNum)
    val x = vals(topIdx)
    vals(topIdx) = 0
    sizes(stackNum) -= 1
    x
  }

  def peek(stackNum: Int): Int = {
    if (isEmpty((stackNum))) throw new EmptyStackException
    vals(idxOfTop(stackNum))
  }

  def isEmpty(stackNum: Int): Boolean = sizes(stackNum) == 0
  def isFull(stackNum: Int): Boolean = sizes(stackNum) == capacity
  def idxOfTop(stackNum: Int): Int = {
    val offset = stackNum * capacity
    val size = sizes(stackNum)
    offset + size - 1
  }
}
