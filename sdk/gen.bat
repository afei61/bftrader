protoc -I ./api --python_out=python --grpc_out=python --plugin=protoc-gen-grpc=../third_party/grpc/bin/grpc_python_plugin.exe ./api/bftrader.proto
protoc -I ./api --cpp_out=cpp --grpc_out=cpp --plugin=protoc-gen-grpc=../third_party/grpc/bin/grpc_cpp_plugin.exe ./api/bftrader.proto
protoc -I ./api --go_out=plugins=grpc:golang ./api/bftrader.proto

protoc -I ./api --python_out=python --grpc_out=python --plugin=protoc-gen-grpc=../third_party/grpc/bin/grpc_python_plugin.exe ./api/bfgateway.proto
protoc -I ./api --cpp_out=cpp --grpc_out=cpp --plugin=protoc-gen-grpc=../third_party/grpc/bin/grpc_cpp_plugin.exe ./api/bfgateway.proto
protoc -I ./api --go_out=plugins=grpc:golang ./api/bfgateway.proto

protoc -I ./api --python_out=python --grpc_out=python --plugin=protoc-gen-grpc=../third_party/grpc/bin/grpc_python_plugin.exe ./api/bfproxy.proto
protoc -I ./api --cpp_out=cpp --grpc_out=cpp --plugin=protoc-gen-grpc=../third_party/grpc/bin/grpc_cpp_plugin.exe ./api/bfproxy.proto
protoc -I ./api --go_out=plugins=grpc:golang ./api/bfproxy.proto

protoc -I ./api --python_out=python --grpc_out=python --plugin=protoc-gen-grpc=../third_party/grpc/bin/grpc_python_plugin.exe ./api/bfdatafeed.proto
protoc -I ./api --cpp_out=cpp --grpc_out=cpp --plugin=protoc-gen-grpc=../third_party/grpc/bin/grpc_cpp_plugin.exe ./api/bfdatafeed.proto
protoc -I ./api --go_out=plugins=grpc:golang ./api/bfdatafeed.proto

protoc -I ./api --python_out=python --grpc_out=python --plugin=protoc-gen-grpc=../third_party/grpc/bin/grpc_python_plugin.exe ./api/bfkv.proto
protoc -I ./api --cpp_out=cpp --grpc_out=cpp --plugin=protoc-gen-grpc=../third_party/grpc/bin/grpc_cpp_plugin.exe ./api/bfkv.proto
protoc -I ./api --go_out=plugins=grpc:golang ./api/bfkv.proto

protoc -I ./api --python_out=python --grpc_out=python --plugin=protoc-gen-grpc=../third_party/grpc/bin/grpc_python_plugin.exe ./api/bfcta.proto
protoc -I ./api --cpp_out=cpp --grpc_out=cpp --plugin=protoc-gen-grpc=../third_party/grpc/bin/grpc_cpp_plugin.exe ./api/bfcta.proto
protoc -I ./api --go_out=plugins=grpc:golang ./api/bfcta.proto

protoc -I ./api --python_out=python --grpc_out=python --plugin=protoc-gen-grpc=../third_party/grpc/bin/grpc_python_plugin.exe ./api/bfrobot.proto
protoc -I ./api --cpp_out=cpp --grpc_out=cpp --plugin=protoc-gen-grpc=../third_party/grpc/bin/grpc_cpp_plugin.exe ./api/bfrobot.proto
protoc -I ./api --go_out=plugins=grpc:golang ./api/bfrobot.proto