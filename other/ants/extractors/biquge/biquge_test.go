package biquge

import (
	"ants/utils"
	"fmt"
	"testing"

	"github.com/ahuigo/requests"
)

var request *requests.Session

var user_agent = `Mozilla/5.0(iPad;U;CPUOS4_3_3likeMacOSX;en-us)AppleWebKit/533.17.9(KHTML,likeGecko)Version/5.0.2Mobile/8J2Safari/6533.18.5`

func Test_biquge(t *testing.T) {
	request = requests.NewSession()
	request.SetGlobalHeader("User-Agent", user_agent)
	resp, err := request.Get("http://www.biqu5200.net/")

	// var header = requests.Header{"Host": "mmzztt.com"}
	// resp, err := request.Get("https://mmzztt.com", header)

	if err != nil {
		// fmt.Println(request, resp.StatusCode())
		fmt.Println(err)
		return
	}

	if utils.GetCharset(resp) == "gbk" {
		fmt.Println(utils.GBK_To_UTF8(resp.Text()))
	} else {
		fmt.Println(resp.Text())
	}
}
