# projectX API v1
## /user/ section

#### POST  /user
register user, checks if name is valid and not occupied

body: `{username: "", password: ""}`

responses: `200 / 400 / 500` with text message

#### GET  /user
returns info about authorized user
not implemented

#### POST  /user/login
login as user

body: `{username: "", password: ""}`

responses: `200 / 400 / 401 / 500` with text message and cookie

#### GET  /user/logout

params: `none`

responses: `200 / 401 / 500` with text message
