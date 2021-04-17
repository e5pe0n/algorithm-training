package scala

import java.util.Stack

class MultiStack(private val numOfStack: Int, private val defaultSize: Int) {
  class StackInfo(private val holder: MultiStack, var start: Int, var capacity: Int) {
    var size: Int

    def isWithinStackCapacity(idx: Int): Boolean = {
      if (idx < 0 || idx >= holder.vals.length) return false
      val contiguousIdx = if (idx < start) idx + holder.vals.length else idx
      val end = start + capacity

      start <= contiguousIdx && contiguousIdx < end
    }

    def lastCapacityIdx: Int = holder.adjustIdx(start + capacity - 1)
    def lastElemIdx: Int = holder.adjustIdx(start + size - 1)
    def isFull: Boolean = size == capacity
    def isEmpty: Boolean = size == 0
  }

  private val info: Array[StackInfo] = (for (i <- 0 until numOfStack)
    yield new StackInfo(this, defaultSize * i, defaultSize)).to[Array]
  private val vals: Array[Int] = new Array(numOfStack * defaultSize)

  def push(stackNum: Int, x: Int): Unit = {
    if (allStacksAreFull) throw new FullStackException

    val stack = info(stackNum)
    if (stack.isFull) expand(stackNum)

    stack.size += 1
    vals(stack.lastElemIdx) = x
  }

  def pop(stackNum: Int): Int = {
    val stack = info(stackNum)
    if (stack.isEmpty) throw EmptyStackException

    val x = vals(stack.lastElemIdx)
    vals(stack.lastElemIdx) = 0
    stack.size -= 1

    x
  }

  def peek(stackNum: Int): Int = {
    val stack = info(stackNum)

    vals[stack.lastElemIdx]
  }

  def shift(stackNum: Int): Unit = {
    val stack = info(stackNum)

    if (stack.size >= stack.capacity) {
      val nextStack = (stackNum + 1) % info.length
      shift(nextStack)
      stack.capacity += 1
    }

    var idx = stack.lastCapacityIdx
    while (stack.isWithinStackCapacity(idx)) {
      vals(idx) = vals(previousIdx(idx))
      idx = previousIdx(idx)
    }

    vals(stack.start) = 0
    stack.start = nextIdx(stack.start)
    stack.capacity -= 1
  }

  def expand(stackNum: Int): Unit = {
    shift((stackNum + 1) % info.length)
    info(stackNum).capacity += 1
  }

  def numOfElems: Int = (for (sd <- info) yield sd.size).foldRight(0)(_ + _)
  def allStacksAreFull: Boolean = numOfElems == vals.length
  def adjustIdx(idx: Int): Int = {
    val ma = vals.length

    ((idx % ma) + ma) % ma
  }
  def nextIdx(idx: Int): Int = adjustIdx(idx + 1)
  def previousIdx(idx: Int): Int = adjustIdx(idx - 1)
}
