package scala

object Main_03_05_01 extends App {
  def sortStack(s: Stack): Unit = {
    val work = new Stack(s.size)
    while (!s.isEmpty) {
      val x = s.pop()
      while (!work.isEmpty && x < work.peek()) {
        s.push(work.pop())
      }
      work.push(x)
    }
    while (!work.isEmpty) {
      s.push(work.pop())
    }
  }

  val s = new Stack(10)
  s.push(30)
  s.push(80)
  s.push(20)
  s.push(40)
  s.push(10)
  s.push(70)
  s.push(60)
  s.push(50)
  sortStack(s)
  while (!s.isEmpty) {
    println(s.pop())
  }
}

// 10
// 20
// 30
// 40
// 50
// 60
// 70
// 80
