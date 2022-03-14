package main

import (
	"gerrit.o-ran-sc.org/r/ric-app/rc-sub/control"
)

func main() {
	c := control.NewControl()
	c.Run()
}

