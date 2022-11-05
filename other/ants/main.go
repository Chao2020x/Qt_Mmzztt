package main

import (
	"io"
	"net/http"
	"os"

	"github.com/gin-gonic/gin"
)

// HelloMmzztt
func HelloMmzztt(c *gin.Context) {
	c.String(http.StatusOK, "Welcome to MMZZTT.COM")
}

func main() {
	// 记录到文件。
	// Main001()
	// return
	f, _ := os.Create("gin.log")
	gin.DefaultWriter = io.MultiWriter(f)
	router := gin.Default()
	router.GET("/", HelloMmzztt)
	// biquge.Loader(router)
	router.Run(":8080")
}
