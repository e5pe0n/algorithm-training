package scala

import scala.collection.mutable.{ArrayBuffer, Queue}
import scala.io.Source

object Main_04_01_v01 extends App {
  def bfs(graph: Array[ArrayBuffer[Int]], numOfVertices: Int, src: Int, dst: Int): Boolean = {
    val visited = (for (_ <- 0 until numOfVertices) yield false).toArray
    visited(src) = true
    val q = new Queue[Int]()
    q.enqueue(src)
    while (!q.isEmpty) {
      val u = q.dequeue()
      for (v <- graph(u)) {
        if (!visited(v)) {
          visited(v) = true
          if (v == dst) return true
          q.enqueue(v)
        }
      }
    }
    return false
  }

  def solve(path: String): Unit = {
    val lines = Source.fromFile(path).getLines()
    val Array(n, m, s, t) = lines.next().split(' ').map(x => x.toInt);
    val graph = new Array[ArrayBuffer[Int]](n).map(_ => new ArrayBuffer[Int]())
    for (i <- 0 until m) {
      val Array(u, v) = lines.next().split(' ').map(x => x.toInt)
      graph(u - 1) += v - 1
    }
    println(bfs(graph, n, s - 1, t - 1))
  }

  solve("../testcases/04_01_01.txt")
  solve("../testcases/04_01_02.txt")
  solve("../testcases/04_01_03.txt")
}

// true
// false
// true
