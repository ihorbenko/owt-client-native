/*
 * Intel License
 */
#ifndef WOOGEEN_BASE_FRAMEGENERATORINTERFACE_H_
#define WOOGEEN_BASE_FRAMEGENERATORINTERFACE_H_

namespace woogeen {
namespace base {
/**
 @brief frame generator interface for audio
 @detail Sample rate and channel numbers cannot be changed once the generator is
 created. Currently, only 16 bit little-endian PCM is supported.
*/
class AudioFrameGeneratorInterface {
 public:
  /**
   @brief Generate frames for next 10ms.
   @param buffer Points to the start address for frame data. The memory is
   allocated and owned by SDK. Implementations should fill frame data to the
   memory starts from |buffer|.
   @param capacity Buffer's capacity. It will be equal or greater to expected
   frame buffer size.
   @return The size of actually frame buffer size.
   */
  virtual uint32_t GenerateFramesForNext10Ms(uint8_t* buffer,
                                             const uint32_t capacity) = 0;
  /// Get sample rate for frames generated.
  virtual int GetSampleRate() = 0;
  /// Get numbers of channel for frames generated.
  virtual int GetChannelNumber() = 0;
  virtual ~AudioFrameGeneratorInterface(){};
};

/**
 @brief frame generator interface for users to generates frame.

 FrameGeneratorInterface is the virtual class to implement its own frame generator.
*/
class VideoFrameGeneratorInterface {
 public:
  enum VideoFrameCodec {
    I420,
    VP8,
    H264,
  };
  /**
   @brief This function generates one frame data.
   @param buffer Points to the start address for frame data. The memory is
   allocated and owned by SDK. Implementations should fill frame data to the
   memory starts from |buffer|.
   @param capacity Buffer's capacity. It will be equal or greater to expected
   frame buffer size.
   @return The size of actually frame buffer size.
   */
  virtual uint32_t GenerateNextFrame(uint8_t* buffer,
                                     const uint32_t capacity) = 0;
  /**
   @brief This function gets the size of next video frame.
   */
  virtual uint32_t GetNextFrameSize() = 0;
  /**
   @brief This function gets the height of video frame.
   */
  virtual int GetHeight() = 0;
  /**
   @brief This function gets the width of video frame.
   */
  virtual int GetWidth() = 0;
  /**
   @brief This function gets the fps of video frame generator.
   */
  virtual int GetFps() = 0;
  /**
   @brief This function gets the video frame type of video frame generator.
   */
  virtual VideoFrameCodec GetType() = 0;

 protected:
  virtual ~VideoFrameGeneratorInterface(){};
};

} // namespace base
} // namespace woogeen
#endif  // WOOGEEN_BASE_FRAMEGENERATORINTERFACE_H_