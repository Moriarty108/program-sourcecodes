class Stack {
  constructor() {
    this.contents = [];
  }

  push(element) {
    this.contents.push(element);
  }
  pushAll(...elements) {
    this.contents.push(...elements);
  }

  pop() {
    return this.contents.pop();
  }
  toString() {
    return this.contents.toString();
  }
}
