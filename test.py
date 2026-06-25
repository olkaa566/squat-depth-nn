import sys
import os
sys.path.append(os.getcwd())
import cpp_engine

def run_test():
    print("Initializing MultiLayerPercepton: 3 inputs -> 4 hidden -> 1 output.")

    mlp = cpp_engine.MultiLayerPerceptron(3, 4, 1, 0.1)

    #prepare training data, normalize angles by dividing by 180
    good_inputs = cpp_engine.Matrix(1, 3, [75.0/180.0, 80.0/180.0, 85.0/180.0])
    good_target = cpp_engine.Matrix(1, 1, [1.0])

    bad_inputs = cpp_engine.Matrix(1, 3, [95.0/180.0, 105.0/180.0, 100.0/180.0])
    bad_target = cpp_engine.Matrix(1, 1, [0.0])

    #training for 500 epochs
    for epoch in range(1,501):
        mlp.train(good_inputs, good_target)
        mlp.train(bad_inputs, bad_target)

        if epoch % 100 == 0 or epoch == 1:
            prediction_good = mlp.forward(good_inputs).get_data()[0]
            prediction_bad = mlp.forward(bad_inputs).get_data()[0]

            loss = abs(1.0 - prediction_good) + abs(0.0 - prediction_bad)
            print(f"Epoch {epoch:3d} | Total Loss: {loss:.4f} | Deep Squat Pred: {prediction_good:.4f} | Shallow Squat Pred: {prediction_bad:.4f}")

if __name__ == "__main__":
    run_test()