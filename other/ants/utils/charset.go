package utils

import (
	"strings"

	"github.com/ahuigo/requests"
	"github.com/axgle/mahonia"
)

func ChangeDecode(src, srcCode, tagCode string) string {
	srcCoder := mahonia.NewDecoder(srcCode)
	srcResult := srcCoder.ConvertString(src)
	tagCoder := mahonia.NewDecoder(tagCode)
	_, cdata, _ := tagCoder.Translate([]byte(srcResult), true)
	return string(cdata)
}
func GBK_To_UTF8(content string) string {
	return ChangeDecode(content, "gbk", "utf8")
}

func UTF8_To_GBK(content string) string {
	return ChangeDecode(content, "utf8", "gbk")
}

// Encode
func Encode(content string) string {
	return GBK_To_UTF8(content)
}

// GetCharset
func GetCharset(content *requests.Response) string {
	header := content.Header()
	value, ok := header["Content-Type"]
	if !ok || len(value) == 0 {
		return "utf8"
	}
	str := strings.Join(value, "")
	if strings.Contains(strings.ToLower(str), strings.ToLower("GBK")) {
		return "gbk"
	}
	return "utf8"
}
